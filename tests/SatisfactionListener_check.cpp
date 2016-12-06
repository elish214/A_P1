//
// Created by raz on 03/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Driver.h"
#include "../src/listeners/SatisfactionListener.h"

//using testing::Eq;

namespace {
    class SatisfactionListenerTests : public testing::Test {
    public:
        EndTripListener *listener;
        Driver *driver;
        Passenger *passenger;

        SatisfactionListenerTests() {}

        virtual ~SatisfactionListenerTests() {
        }

        virtual void SetUp() {
            driver = new Driver(123456, 32, MaritalStatus::MARRIED);
            Location l1 = Location(0, 0);
            Location l2 = Location(2, 2);
            passenger = new Passenger(l1, l2);
            listener = new SatisfactionListener(driver, passenger);
            driver->addListener(listener);
        }

        virtual void TearDown() {
            driver->removeListener(listener);
            delete driver;
            delete passenger;
            delete listener;
        }

    };
}

/**
 * testing listener rating.
 */
TEST_F(SatisfactionListenerTests, testLRating) {
    driver->notifyAllEndTrip();
    ASSERT_TRUE(driver->getSatisfaction() == 0);
}
