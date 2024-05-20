#include <iostream>
#include <cstdlib>

using namespace std;

int max(int a, int b) {
    if (a > b)
        return a;
 return b;
}

//Solves it in O(n)
int algorithm3(int arr[],int n){
    int best = 0, sum = 0;
	for (int k = 0; k < n; k++) {
		sum = max(arr[k],sum+arr[k]);
		best = max(best,sum);
	}
	return best;
}
//Solves it in O(n^2)
int algorithm2(int arr[],int n){
    int best = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int b = i; b < n; b++) {
			sum += arr[b];
			best = max(best,sum);
		}
	}
    return best;
}
//Solves it in O(n^3)
int algorithm1(int arr[],int n){
    int best = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) sum += arr[k];
			best = max(best,sum);
		}
	}
    return best;
}

int* genarray(long seed, int size){
	int* arr = new int[size];
    	srand(seed); 
    for (int i = 0; i < size; i++) arr[i] = (rand() % 100) - 25;
	return arr;
}


int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    int size = atoi(argv[2]);
    int* arr = genarray(seed, size);
	cout << 1 << endl;
	int alg1 = 0;
	int alg2 = 0;
	int alg3 = 0;
	alg1 = algorithm1(arr, size);
	alg2 = algorithm2(arr, size);
	alg3 = algorithm3(arr, size);
	cout << "O(n^3): " << alg1 << endl;
	cout << "O(n^2): " << alg2 << endl;
	cout << "O(n): " << alg3 << endl;
    return 0;

}
