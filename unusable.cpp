#include <iostream>

using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    arr[6] = 10; // arr[6] is out of bounds
    return 0;
}