cmake_minimum_required(VERSION 3.6)
project(A_P1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")


add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)

include_directories(lib/googletest-master/googlemock/include)


set(BOOST_ROOT CACHE PATH "/usr/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})


set(SOURCE_FILES src/navigation/Point.cpp src/navigation/BFS.cpp
        src/navigation/Grid.cpp src/navigation/Location.cpp src/navigation/Node.h
        src/listeners/EndTripListener.h
        src/listeners/SatisfactionListener.cpp src/listeners/SatisfactionListener.h
        src/listeners/AvailabilityListener.cpp src/listeners/AvailabilityListener.h
        src/Satisfaction.cpp src/Satisfaction.h src/Passenger.cpp src/Passenger.h src/TripInfo.cpp
        src/TripInfo.h src/Driver.cpp src/Driver.h src/enums/MaritalStatus.h src/enums/Color.h
        src/enums/CarManufacturer.h src/taxi/Taxi.cpp src/taxi/Taxi.h src/taxi/StandardTaxi.cpp
        src/taxi/StandardTaxi.h src/taxi/LuxuryTaxi.cpp src/taxi/LuxuryTaxi.h
        src/TaxiCenter.cpp src/TaxiCenter.h tests/Point_check.cpp tests/Driver_check.cpp
        tests/Passenger_check.cpp tests/BFS_check.cpp tests/Grid_check.cpp
        tests/Location_check.cpp tests/Taxi_check.cpp tests/StandardTaxi_check.cpp
        tests/LuxuryTaxi_check.cpp tests/Satisfaction_check.cpp tests/TaxiCenter_check.cpp
        tests/TripInfo_check.cpp tests/main.cpp tests/AvailabilityListener_check.cpp
        tests/SatisfactionListener_check.cpp src/taxi/TaxiFactory.cpp src/taxi/TaxiFactory.h
        src/sockets/Socket.cpp src/sockets/Socket.h src/sockets/Udp.cpp
        src/sockets/Udp.h src/sockets/Tcp.cpp src/sockets/Tcp.h src/sockets/Connection.cpp
        src/sockets/Connection.h src/navigation/Node.cpp src/containers/LocationContainer.cpp
        src/containers/LocationContainer.h src/containers/DriverContainer.cpp
        src/containers/DriverContainer.h src/containers/PassengerContainer.cpp
        src/containers/PassengerContainer.h src/containers/TripContainer.cpp
        src/containers/TripContainer.h src/enums/Operation.h src/containers/Command.cpp
        src/containers/Command.h src/Thread.cpp src/Thread.h src/ThreadPool.cpp src/ThreadPool.h src/validation/Checker.h src/validation/PositiveNumericChecker.cpp src/validation/PositiveNumericChecker.h src/validation/CarManufacturerChecker.cpp src/validation/CarManufacturerChecker.h src/validation/ColorChecker.cpp src/validation/ColorChecker.h src/validation/MaritalStatusChecker.cpp src/validation/MaritalStatusChecker.h src/validation/RangeNumericChecker.cpp src/validation/RangeNumericChecker.h src/validation/Validator.cpp src/validation/Validator.h)

add_executable(Server ${SOURCE_FILES} src/Server.cpp)
add_executable(Client ${SOURCE_FILES} src/Client.cpp)

target_link_libraries(Server gtest gtest_main ${Boost_LIBRARIES})
target_link_libraries(Client gtest gtest_main ${Boost_LIBRARIES})
