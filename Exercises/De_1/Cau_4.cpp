#include <iostream>

using namespace std;

char a[100], value[100];
int n, kk, count;

void sort() {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if( value[i] < value[j] ) swap(value[i], value[j]);
		}
	}
}

void print() {
	for(int i = 1; i <= kk; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

bool same(int k) {
	for(int i = 1; i < k; i++) {
		if( a[i] == a[k] ) return true;
	}
	return false;
}

void recursion(int k) {
	if( k > kk ) {
		print();
		count++;
		if( count == 100 ) exit(0);
	}
	
	else {
		int i = 0;
		for(a[k] = value[i]; i < n; a[k] = value[++i]) {
			if( same(k) ) continue;
			recursion(k + 1);
		}
	}
}

int main() {
	
	cin >> n >> kk;
	for(int i = 0; i < n; i++) {
		cin >> value[i];
	}
	sort();
	recursion(1);
	
	return 0;
}
