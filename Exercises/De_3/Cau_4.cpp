#include <iostream>

using namespace std;

int a[100];
int n, count;

int sum() {
	int s = 0;
	for(int i = 1; i <= n; i++) {
		if( a[i] == 0 ) continue;
		s += a[i];
	}
	return s;
}

void recursion(int k) {
	if( k > n ) {
		if( sum() == n ) {
			count++;
		}
	}
	
	else {
		for(a[k] = ( a[k - 1] == 0 ? 0 : a[k - 1] + 1 ); a[k] <= n; a[k]++) {
			recursion(k + 1);
		}
	}
}

int main() {
	
	cin >> n;
	recursion(1);
	
	cout << count;
	return 0;
}
