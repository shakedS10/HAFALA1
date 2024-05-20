all: main 

main: main.o
	g++ -pg -o main main.o

main.o: main.cpp
	g++ -pg -c main.cpp
	
clean:

	rm -f *.o main
