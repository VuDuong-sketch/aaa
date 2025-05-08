#include <iostream>

using namespace std;

bool Prime(int n) {
	if( n == 2 ) return true;
	if( n < 2 || n % 2 == 0 ) return false;
	for(int i = 3; i * i <= n; i += 2) {
		if( n % i == 0 ) return false;
	}
	return true;
}

int main() {
	
	int l, r, count = 0;
	cin >> l >> r;
	
	for(int i = l; i <= r; i++) {
		if( Prime(i) ) count++;
	}
	
	cout << count;
	
	return 0;
}
