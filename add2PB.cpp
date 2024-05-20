#include <iostream>
#include <unistd.h> 
#include <fstream>
using namespace std;

void add2PB(string filename, string line){
	ofstream f;
	f.open(filename, fstream::app);
	f << line << endl;
	f.close();	
}


int main(int argc, const char * argv[]) {
	string line = "";
	for (int i = 1; i < argc - 1; i++) line += (string)argv[i] + " ";
	line += "," + (string)argv[argc - 1];
  	add2PB("phonebook.txt", line);
  	return 0;
}