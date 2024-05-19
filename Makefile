CC = g++
CFLAGS = -Wall -Wextra -std=c++11

all: dev0 infrec unusable

dev0: dev0.cpp
	$(CC) $(CFLAGS) -o dev0 dev0.cpp

infrec: infrec.cpp
	$(CC) $(CFLAGS) -o infrec infrec.cpp

function3: unusable.cpp
	$(CC) $(CFLAGS) -o unusable unusable.cpp

clean:
	rm -f dev0 infrec unusable