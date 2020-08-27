#pragma once

#include <cassert>
#include <list>
#include <memory>
#include <mutex>
#include <numeric>

class Listener {
public:
    virtual ~Listener() = default;
    virtual void update() = 0;
};

class Observer {
public:
    void notify()
    {
        const auto listeners = getListeners();
        for (const auto& listener : listeners) {
            const auto ptrListener = listener.lock();
            assert(ptrListener != nullptr);
            if (ptrListener != nullptr) {
                ptrListener->update();
            }
        }
    }

    void attach(const std::shared_ptr<Listener>& listener)
    {
        std::lock_guard<std::mutex> lockListeners(_listenersMutex);
        // listener shouldn't be already subscribed
        assert(!std::accumulate(_listeners.begin(), _listeners.end(), false,
            [listener](bool found, const std::weak_ptr<Listener>& listenerIt) {
                return found || !(listenerIt.owner_before(listener) || listener.owner_before(listenerIt));
            }));
        _listeners.push_back(listener);
    }

    void detach(const std::shared_ptr<Listener>& listener)
    {
        std::lock_guard<std::mutex> lockListeners(_listenersMutex);
        _listeners.remove_if([listener](const std::weak_ptr<Listener>& listenerIt) {
            return !(listenerIt.owner_before(listener) || listener.owner_before(listenerIt));
        });
    }

private:
    const std::list<std::weak_ptr<Listener>> getListeners() const
    {
        std::lock_guard<std::mutex> lockListeners(_listenersMutex);
        const auto listeners = _listeners;
        return listeners;
    }

    std::list<std::weak_ptr<Listener>> _listeners;
    mutable std::mutex _listenersMutex;
};