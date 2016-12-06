//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/taxi/Taxi.h"
#include "../src/taxi/StandardTaxi.h"

//using testing::Eq;


namespace {
    class TaxiTests : public testing::Test {
    public:
        StandardTaxi *taxi;

        TaxiTests() {
        }

        virtual ~TaxiTests() {

        }

        virtual void SetUp() {
            taxi = new StandardTaxi(12345, CarManufacturer::HONDA, Color::BLUE);
        }

        virtual void TearDown() {
            delete taxi;
        }    
    };
}

/**
 * testing meter counter.
 */
TEST_F(TaxiTests, testMeter) {
    taxi->addMeters(18.7);
    taxi->addMeters(6.5);

    ASSERT_EQ(taxi->getKmPassed(), 25.2);
}
