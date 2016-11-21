a.out: main.o BFS.o Grid.o Location.o Point.o
	g++ main.o BFS.o Grid.o Location.o Point.o

BFS.o: src/BFS.cpp src/BFS.h
	g++ -c -std=c++11 src/BFS.cpp

Grid.o: src/Grid.cpp src/Grid.h
	g++ -c -std=c++11 src/Grid.cpp

Location.o: src/Location.cpp src/Location.h
	g++ -c -std=c++11 src/Location.cpp

Point.o: src/Point.cpp src/Point.h
	g++ -c -std=c++11 src/Point.cpp

main.o: src/main.cpp src/Node.h
	g++ -c -std=c++11 src/main.cpp

clean: 
	rm -f *.o a.out
