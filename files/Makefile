##############################
#204728299_Raz_Solomon       #
#302860986_Elisheva_Broyer   #
##############################

a.out: main.o AvailabilityListener.o SatisfactionListener.o BFS.o Grid.o Location.o Point.o LuxuryTaxi.o StandardTaxi.o Taxi.o TaxiFactory.o Driver.o Flow.o Passenger.o Satisfaction.o TaxiCenter.o TripInfo.o
	g++ main.o AvailabilityListener.o SatisfactionListener.o BFS.o Grid.o Location.o Point.o LuxuryTaxi.o StandardTaxi.o Taxi.o TaxiFactory.o Driver.o Flow.o Passenger.o Satisfaction.o TaxiCenter.o TripInfo.o

main.o: src/main.cpp src/navigation/Node.h src/enums/CarManufacturer.h src/enums/Color.h src/enums/MaritalStatus.h src/listeners/EndTripListener.h
	g++ -c -std=c++0x -Wall src/main.cpp

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

Point.o: src/navigation/Point.cpp src/navigation/Point.h
	g++ -c -std=c++0x -Wall src/navigation/Point.cpp

LuxuryTaxi.o: src/taxi/LuxuryTaxi.cpp src/taxi/LuxuryTaxi.h
	g++ -c -std=c++0x -Wall src/taxi/LuxuryTaxi.cpp

StandardTaxi.o: src/taxi/StandardTaxi.cpp src/taxi/StandardTaxi.h
	g++ -c -std=c++0x -Wall src/taxi/StandardTaxi.cpp

Taxi.o: src/taxi/Taxi.cpp src/taxi/Taxi.h
	g++ -c -std=c++0x -Wall src/taxi/Taxi.cpp

TaxiFactory.o: src/taxi/TaxiFactory.cpp src/taxi/TaxiFactory.h
	g++ -c -std=c++0x -Wall src/taxi/TaxiFactory.cpp

Driver.o: src/Driver.cpp src/Driver.h
	g++ -c -std=c++0x -Wall src/Driver.cpp

Flow.o: src/Flow.cpp src/Flow.h
	g++ -c -std=c++0x -Wall src/Flow.cpp

Passenger.o: src/Passenger.cpp src/Passenger.h
	g++ -c -std=c++0x -Wall src/Passenger.cpp

Satisfaction.o: src/Satisfaction.cpp src/Satisfaction.h
	g++ -c -std=c++0x -Wall src/Satisfaction.cpp

TaxiCenter.o: src/TaxiCenter.cpp src/TaxiCenter.h
	g++ -c -std=c++0x -Wall src/TaxiCenter.cpp

TripInfo.o: src/TripInfo.cpp src/TripInfo.h
	g++ -c -std=c++0x -Wall src/TripInfo.cpp

clean: 
	rm -f *.o a.out
