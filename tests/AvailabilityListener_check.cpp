//
// Created by raz on 03/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

//using testing::Eq;

namespace {
    class AvailabilityTests : public testing::Test {
    public:
        //EndTripListener *listener;
        //Driver *driver;

        AvailabilityTests() {}

        virtual ~AvailabilityTests() {
        }

        virtual void SetUp() {
            /*
            Driver d = Driver(11,23, MaritalStatus::SINGLE, 2);
            driver = new Driver(123456, 32, MaritalStatus::MARRIED,0);
            listener = new AvailabilityListener(driver);
            driver->addListener(listener);
             */
        }

        virtual void TearDown() {
          /*
            driver->removeListener(listener);
            delete driver;
            delete listener;
           */
        }

    };
}

/**
 * test availabilty of a driver.
 */
TEST_F(AvailabilityTests, testAvailable) {
    /*
     * currently isn't implemented.
    driver->setAvailability(false);
    driver->notifyAllEndTrip();
    ASSERT_EQ(driver->isAvailabile(), true);
     */
}
