##############################
#204728299_Raz_Solomon       #
#302860986_Elisheva_Broyer   #
##############################

a.out: main.o BFS.o Grid.o Location.o Point.o
	g++ main.o BFS.o Grid.o Location.o Point.o

main.o: src/main.cpp src/Node.h
	g++ -c src/main.cpp

BFS.o: src/BFS.cpp src/BFS.h
	g++ -c src/BFS.cpp

Grid.o: src/Grid.cpp src/Grid.h
	g++ -c src/Grid.cpp

Location.o: src/Location.cpp src/Location.h
	g++ -c src/Location.cpp

Point.o: src/Point.cpp src/Point.h
	g++ -c src/Point.cpp

clean: 
	rm -f *.o a.out
