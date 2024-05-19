#include <stdio.h>
#include <stdlib.h>
#include "poisson.h"

int main() {
    printf("%Lf\n", poisson(0.3, 3));
    printf("%Lf\n", poisson(0.3, 4));
    printf("%Lf\n", poisson(0.3, 5));
    printf("%Lf\n", poisson(0.5, 6));
    printf("%Lf\n", poisson(0.5, 7));
    return 0;
}
