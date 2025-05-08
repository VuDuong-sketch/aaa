#include <iostream>

using namespace std;

int a[100][100];

int sum(int x, int y, int w, int h) {
	int s = 0;
	
	for(int i = y; i <= y + h - 1; i++) {
		for(int j = x; j <= x + w - 1; j++) {
			s += a[i][j];
		}
	}
	
	return s;
}

int main() {
	
	
	
	int m, n, q, k;
	cin >> m >> n >> q >> k;
	
	int max = 0;
	
	for(int i = 1; i <= q; i++) {
		int x, y, v;
		cin >> x >> y >> v;
		a[y][x] = v;
	}
	
	for(int i = 1; i <= k; i++) {
		int x, y, w, h;
		cin >> x >> y >> w >> h;
		int s = sum(x, y, w, h);
		if( s > max ) max = s;
	}
	
	cout << max;
	
	
	
	
	return 0;
	
}













