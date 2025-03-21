#include <iostream>
using namespace std;

void sizeArray(int a[]) {
	cout << sizeof(a) / sizeof(int) << endl;
}

int main() {
	int a[10];
	
	sizeArray(a);
	
	cout << sizeof(a) / sizeof(int) << endl;
	return 0;
}
