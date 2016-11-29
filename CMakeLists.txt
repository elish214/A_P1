cmake_minimum_required(VERSION 3.6)
project(A_P1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/navigation/Point.cpp src/navigation/BFS.cpp src/navigation/Grid.cpp src/navigation/Location.cpp src/navigation/Node.h src/listeners/EndTripListener.h src/listeners/SatisfactionListener.cpp src/listeners/SatisfactionListener.h src/listeners/AvailabilityListener.cpp src/listeners/AvailabilityListener.h src/Satisfaction.cpp src/Satisfaction.h src/Passenger.cpp src/Passenger.h src/TripInfo.cpp src/TripInfo.h src/Driver.cpp src/Driver.h src/enums/MaritalStatus.h src/enums/Color.h src/enums/CarManufacturer.h src/taxi/Taxi.cpp src/taxi/Taxi.h src/taxi/StandardTaxi.cpp src/taxi/StandardTaxi.h src/taxi/LuxuryTaxi.cpp src/taxi/LuxuryTaxi.h src/TaxiCenter.cpp src/TaxiCenter.h test/Point_check.cpp test/main_check.cpp)

add_executable(A_P1 ${SOURCE_FILES})

add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)

include_directories(lib/googletest-master/googlemock/include)

target_link_libraries(A_P1 gtest gtest_main)