#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include "poisson.h"

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

long double poisson(long double parameter,int k){
    return (pow(parameter,k)/factorial(k)) * expf(-parameter);
}


