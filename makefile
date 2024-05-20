all: add2PB findPhone

add2PB: add2PB.o
	g++ -o add2PB add2PB.o

findPhone: findPhone.o
	g++ -o findPhone findPhone.o

add2PB.o: add2PB.cpp
	g++ -c add2PB.cpp

findPhone.o: findPhone.cpp
	g++ -c findPhone.cpp
	
clean:
	rm -f *.o add2PB findPhone
