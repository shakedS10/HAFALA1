#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

long double poisson(long double parameter,int k){
    return exp(-parameter)*pow(parameter,k)/factorial(k);
}

int main(int argc,char** argv){
    if(argc!=3){
        std::cout << "ERORR" << std::endl;
        return 1;
    }
    long double parameter = stold(argv[1]);
    int k = atoi(argv[2]);
    std::cout << poisson(parameter,k) << std::endl;
    return 0;
}
