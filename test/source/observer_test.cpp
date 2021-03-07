#include <gtest/gtest.h>
#include <include/observer.h>

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

TEST(Observer, attach_notify)
{
    static constexpr int VERIFICATION_VALUE = 1;
    const auto listener = std::make_shared<TestListener>(VERIFICATION_VALUE);
    Observer observer;

    observer.attach(listener);
    observer.notify();

    EXPECT_EQ(listener->value, VERIFICATION_VALUE);
}