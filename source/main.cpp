#include <include/observer.h>
#include <iostream>
#include <thread>
#include <vector>

struct TestListener : public Listener {
    explicit TestListener(int value)
        : verificationValue(value)
        , value(!verificationValue)
    {
    }

    virtual void update() override
    {
        value = verificationValue;
    }

    const int verificationValue;
    int value;
};

int main()
{
    Observer observer;
    const auto listener = std::make_shared<TestListener>(1);

    observer.attach(listener);
    observer.notify();

    if (listener->value != listener->verificationValue) {
        std::cerr << "Fail!" << std::endl;
        return 1;
    }

    std::cout << "Successful!" << std::endl;
    return 0;
}
