#include <iostream>

using namespace std;



int main() {
	
	
	
	int n;
	cin >> n;
	int a[1000];
	for(int i = 0; i < n; i++) cin >> a[i];
	
	
	
	for(int i = 0; i < n;) {
		bool odd = ( a[i] % 2 != 0 );
		int count = 0, j = i;
		if( odd ) for(j = i; j < n; j++) {
			if( a[j] % 2 == 0 ) break;
			count++;
		}
		else for(j = i; j < n; j++) {
			if( a[j] % 2 != 0 ) break;
			count++;
		}
		cout << count << ' ';
		i = j;
	}
	
	return 0;
}












