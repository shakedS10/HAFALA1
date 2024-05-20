CC = gcc
 
 all: dijkstra


dijkstra: dijkstra.c
	$(CC) -Wall -fprofile-arcs -ftest-coverage -o dijkstra dijkstra.c
clean:
	rm -f dijkstra *.o *.gcno *.gcda *.gcov