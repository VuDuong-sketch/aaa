#include <iostream>

using namespace std;

void print(int a[], int size) {
	for(int i = 0; i < size; i++) {
		cout << a[i] << ' ';
	}
}

int main() {
	int a[] = {5, 4, 3, 2, 1};
	const int SIZE = 5;
	
	for(int i = SIZE - 2; i >= 0; i--) {
		for(int j = 0; j <= i; j++) {
			if( a[j] > a[j + 1] ) swap(a[j], a[j + 1]);
		}
	}
	
	print(a, SIZE);
	
	return 0;
}
