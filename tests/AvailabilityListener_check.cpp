//
// Created by raz on 03/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Driver.h"
#include "../src/listeners/AvailabilityListener.h"

//using testing::Eq;

namespace {
    class AvailabilityTests : public testing::Test {
    public:
        EndTripListener *listener;
        Driver *driver;

        AvailabilityTests() {}

        virtual ~AvailabilityTests() {
        }

        virtual void SetUp() {
            driver = new Driver(123456, 32, MaritalStatus::MARRIED);
            listener = new AvailabilityListener(driver);
            driver->addListener(listener);
        }

        virtual void TearDown() {
            driver->removeListener(listener);
            delete driver;
            delete listener;
        }

    };
}

/**
 * test availabilty of a driver.
 */
TEST_F(AvailabilityTests, testAvailable) {
    driver->setAvailability(false);
    driver->notifyAllEndTrip();
    ASSERT_EQ(driver->isAvailability(), true);
}
