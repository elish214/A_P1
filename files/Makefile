##############################
#204728299_Raz_Solomon       #
#302860986_Elisheva_Broyer   #
##############################

all: server.out client.out

server.out: Server.o Command.o DriverContainer.o LocationContainer.o PassengerContainer.o TripContainer.o AvailabilityListener.o SatisfactionListener.o BFS.o Grid.o Location.o Node.o Point.o Connection.o Socket.o Tcp.o Udp.o LuxuryTaxi.o StandardTaxi.o Taxi.o TaxiFactory.o CarManufacturerChecker.o ColorChecker.o MaritalStatusChecker.o PositiveNumericChecker.o RangeNumericChecker.o Validator.o Driver.o Passenger.o Satisfaction.o TaxiCenter.o Thread.o TripInfo.o
	g++ -g -o server.out Server.o Command.o DriverContainer.o LocationContainer.o PassengerContainer.o TripContainer.o AvailabilityListener.o SatisfactionListener.o BFS.o Grid.o Location.o Node.o Point.o Connection.o Socket.o Tcp.o Udp.o LuxuryTaxi.o StandardTaxi.o Taxi.o TaxiFactory.o CarManufacturerChecker.o ColorChecker.o MaritalStatusChecker.o PositiveNumericChecker.o RangeNumericChecker.o Validator.o Driver.o Passenger.o Satisfaction.o TaxiCenter.o Thread.o TripInfo.o -lboost_serialization -pthread

client.out: Client.o Command.o DriverContainer.o LocationContainer.o PassengerContainer.o TripContainer.o AvailabilityListener.o SatisfactionListener.o BFS.o Grid.o Location.o Node.o Point.o Connection.o Socket.o Tcp.o Udp.o LuxuryTaxi.o StandardTaxi.o Taxi.o TaxiFactory.o CarManufacturerChecker.o ColorChecker.o MaritalStatusChecker.o PositiveNumericChecker.o RangeNumericChecker.o Validator.o Driver.o Passenger.o Satisfaction.o TaxiCenter.o Thread.o TripInfo.o
	g++ -g -o client.out Client.o Command.o DriverContainer.o LocationContainer.o PassengerContainer.o TripContainer.o AvailabilityListener.o SatisfactionListener.o BFS.o Grid.o Location.o Node.o Point.o Connection.o Socket.o Tcp.o Udp.o LuxuryTaxi.o StandardTaxi.o Taxi.o TaxiFactory.o CarManufacturerChecker.o ColorChecker.o MaritalStatusChecker.o PositiveNumericChecker.o RangeNumericChecker.o Validator.o Driver.o Passenger.o Satisfaction.o TaxiCenter.o Thread.o TripInfo.o -lboost_serialization -pthread

Server.o: src/Server.cpp src/navigation/Node.h src/enums/CarManufacturer.h src/enums/Color.h src/enums/MaritalStatus.h src/listeners/EndTripListener.h src/validation/Checker.h
	g++ -g -c -std=c++0x -Wall src/Server.cpp

Client.o: src/Client.cpp src/navigation/Node.h src/enums/CarManufacturer.h src/enums/Color.h src/enums/MaritalStatus.h src/listeners/EndTripListener.h src/validation/Checker.h
	g++ -g -c -std=c++0x -Wall src/Client.cpp

Command.o: src/containers/Command.cpp src/containers/Command.h
	g++ -c -std=c++0x -Wall src/containers/Command.cpp

DriverContainer.o: src/containers/DriverContainer.cpp src/containers/DriverContainer.h
	g++ -c -std=c++0x -Wall src/containers/DriverContainer.cpp

LocationContainer.o: src/containers/LocationContainer.cpp src/containers/LocationContainer.h
	g++ -c -std=c++0x -Wall src/containers/LocationContainer.cpp

PassengerContainer.o: src/containers/PassengerContainer.cpp src/containers/PassengerContainer.h
	g++ -c -std=c++0x -Wall src/containers/PassengerContainer.cpp

TripContainer.o: src/containers/TripContainer.cpp src/containers/TripContainer.h
	g++ -c -std=c++0x -Wall src/containers/TripContainer.cpp

AvailabilityListener.o: src/listeners/AvailabilityListener.cpp src/listeners/AvailabilityListener.h
	g++ -c -std=c++0x -Wall src/listeners/AvailabilityListener.cpp

SatisfactionListener.o: src/listeners/SatisfactionListener.cpp src/listeners/SatisfactionListener.h
	g++ -c -std=c++0x -Wall src/listeners/SatisfactionListener.cpp

BFS.o: src/navigation/BFS.cpp src/navigation/BFS.h
	g++ -c -std=c++0x -Wall src/navigation/BFS.cpp

Grid.o: src/navigation/Grid.cpp src/navigation/Grid.h
	g++ -c -std=c++0x -Wall src/navigation/Grid.cpp

Location.o: src/navigation/Location.cpp src/navigation/Location.h
	g++ -c -std=c++0x -Wall src/navigation/Location.cpp

Node.o: src/navigation/Node.cpp src/navigation/Node.h
	g++ -c -std=c++0x -Wall src/navigation/Node.cpp

Point.o: src/navigation/Point.cpp src/navigation/Point.h
	g++ -c -std=c++0x -Wall src/navigation/Point.cpp

Connection.o: src/sockets/Connection.cpp src/sockets/Connection.h
	g++ -c -std=c++0x -Wall src/sockets/Connection.cpp

Socket.o: src/sockets/Socket.cpp src/sockets/Socket.h
	g++ -c -std=c++0x -Wall src/sockets/Socket.cpp

Tcp.o: src/sockets/Tcp.cpp src/sockets/Tcp.h
	g++ -c -std=c++0x -Wall src/sockets/Tcp.cpp

Udp.o: src/sockets/Udp.cpp src/sockets/Udp.h
	g++ -c -std=c++0x -Wall src/sockets/Udp.cpp

LuxuryTaxi.o: src/taxi/LuxuryTaxi.cpp src/taxi/LuxuryTaxi.h
	g++ -c -std=c++0x -Wall src/taxi/LuxuryTaxi.cpp

StandardTaxi.o: src/taxi/StandardTaxi.cpp src/taxi/StandardTaxi.h
	g++ -c -std=c++0x -Wall src/taxi/StandardTaxi.cpp

Taxi.o: src/taxi/Taxi.cpp src/taxi/Taxi.h
	g++ -c -std=c++0x -Wall src/taxi/Taxi.cpp

TaxiFactory.o: src/taxi/TaxiFactory.cpp src/taxi/TaxiFactory.h
	g++ -c -std=c++0x -Wall src/taxi/TaxiFactory.cpp

CarManufacturerChecker.o: src/validation/CarManufacturerChecker.cpp src/validation/CarManufacturerChecker.h
    g++ -c -std=c++0x -Wall src/validation/CarManufacturerChecker.cpp

ColorChecker.o: src/validation/ColorChecker.cpp src/validation/ColorChecker.h
    g++ -c -std=c++0x -Wall src/validation/ColorChecker.cpp

MaritalStatusChecker.o: src/validation/MaritalStatusChecker.cpp src/validation/MaritalStatusChecker.h
    g++ -c -std=c++0x -Wall src/validation/MaritalStatusChecker.cpp

PositiveNumericChecker.o: src/validation/PositiveNumericChecker.cpp src/validation/PositiveNumericChecker.h
    g++ -c -std=c++0x -Wall src/validation/PositiveNumericChecker.cpp

RangeNumericChecker.o: src/validation/RangeNumericChecker.cpp src/validation/RangeNumericChecker.h
    g++ -c -std=c++0x -Wall src/validation/RangeNumericChecker.cpp

Validator.o: src/validation/Validator.cpp src/validation/Validator.h
    g++ -c -std=c++0x -Wall src/validation/Validator.cpp

Driver.o: src/Driver.cpp src/Driver.h
	g++ -c -std=c++0x -Wall src/Driver.cpp

Passenger.o: src/Passenger.cpp src/Passenger.h
	g++ -c -std=c++0x -Wall src/Passenger.cpp

Satisfaction.o: src/Satisfaction.cpp src/Satisfaction.h
	g++ -c -std=c++0x -Wall src/Satisfaction.cpp

TaxiCenter.o: src/TaxiCenter.cpp src/TaxiCenter.h
	g++ -c -std=c++0x -Wall src/TaxiCenter.cpp

Thread.o: src/Thread.cpp src/Thread.h
	g++ -c -std=c++0x -Wall src/Thread.cpp

TripInfo.o: src/TripInfo.cpp src/TripInfo.h
	g++ -c -std=c++0x -Wall src/TripInfo.cpp

clean: 
	rm -f *.o server.out client.out
