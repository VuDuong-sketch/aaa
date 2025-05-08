#include <iostream>

using namespace std;

int n, kk, count;
char variable[100];
char value[100];

void sort() {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if( value[i] > value[j] ) swap(value[i], value[j]);
		}
	}
}

void print() {
	for(int i = 1; i <= kk; i++) {
		cout << variable[i] << ' ';
	}
	cout << endl;
}

void recursion(int k) {
	if( k > kk ) {
		print();
		count++;
		if( count == 100 ) exit(0);
	}
	
	else {
		int i = 0;
		for(variable[k] = value[i]; i < n; variable[k] = value[++i]) {
			recursion(k + 1);
		}
	}
}

int main() {
	
	cin >> n >> kk;
	for(int i = 0; i < n; i++) cin >> value[i];
	sort();
	
	recursion(1);
	
	return 0;
}
