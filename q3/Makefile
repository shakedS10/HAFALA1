
CC = gcc
CFLAGS = -Wall

all:  poissondyn

poisson.o: poisson.c
	$(CC) $(CFLAGS) -fPIC -c poisson.c
libpoisson.so: poisson.o
	$(CC) -shared -o $@ $^
poissondyn: poissondyn.o libpoisson.so
	$(CC) $(CFLAGS) -o poissondyn poissondyn.o ./libpoisson.so -lm
poissondyn.o: poissondyn.c 
	$(CC) $(CFLAGS) -fPIC -c poissondyn.c

clean:
	rm -f poisson poissondyn *.o *.so
