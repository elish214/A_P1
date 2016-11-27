##############################
#204728299_Raz_Solomon       #
#302860986_Elisheva_Broyer   #
##############################

a.out: main.o BFS.o Grid.o Location.o Point.o
	g++ main.o BFS.o Grid.o Location.o Point.o

main.o: main.cpp Node.h
	g++ -c -std=c++0x main.cpp

BFS.o: BFS.cpp BFS.h
	g++ -c -std=c++0x BFS.cpp

Grid.o: Grid.cpp Grid.h
	g++ -c -std=c++0x Grid.cpp

Location.o: Location.cpp Location.h
	g++ -c -std=c++0x Location.cpp

Point.o: Point.cpp Point.h
	g++ -c -std=c++0x Point.cpp

clean: 
	rm -f *.o a.out
