//
// Created by raz on 03/12/16.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Driver.h"
#include "../src/listeners/SatisfactionListener.h"

using testing::Eq;

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

TEST_F(SatisfactionListenerTests, testRating) {
    driver->notifyAllEndTrip();
    ASSERT_FALSE(driver->getSatisfaction() == 0);
}