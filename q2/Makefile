CC = g++
CFLAGS = -Wall -Wextra -std=c++11

all: poisson

poisson: poisson.cpp poisson.hpp
	$(CC) $(CFLAGS) -o poisson poisson.cpp -lm

clean:
	rm -f poisson
