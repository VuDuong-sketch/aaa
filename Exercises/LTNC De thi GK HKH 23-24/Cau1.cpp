#include <iostream>
using namespace std;

int a[100];
int S[100];

int sum(int i, int j) {
	if(i == 0) return S[j];
	
	int s = 0;

	s = S[j] - S[i - 1];
	
	return s;
	
}

int main() {
	int n, k;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> k;
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if( a[i] + a[j] == k ) {
				cout << a[i] << ' ' << a[j] << endl;
			}
		}
	}
	return 0;
}




