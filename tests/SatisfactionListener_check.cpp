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
        /*
        EndTripListener *listener;
        Driver *driver;
        Passenger *passenger;
        Location *l1;
        Location *l2;
        */

        SatisfactionListenerTests() {}

        virtual ~SatisfactionListenerTests() {
        }

        virtual void SetUp() {
            /*
            driver = new Driver(123456, 32, MaritalStatus::MARRIED, 0);
            l1 = new Location(0, 0);
            l2 = new Location(2, 2);
            passenger = new Passenger(l1, l2);
            listener = new SatisfactionListener(driver, passenger);
            driver->addListener(listener);
             */
        }

        virtual void TearDown() {
            /*
          //  driver->removeListener(listener);
         //   delete driver;
          //  delete passenger;
           // delete listener;
          //  delete l1;
            //delete l2;
        */
        }

    };
}

/**
 * testing listener rating.
 */
TEST_F(SatisfactionListenerTests, testLRating) {
    /*
     currently isn't implemented.
    driver->notifyAllEndTrip();
    ASSERT_TRUE(driver->getSatisfaction() == 0);
     */
}
