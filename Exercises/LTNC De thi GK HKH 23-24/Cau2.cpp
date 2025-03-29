#include <iostream>
using namespace std;

int a[30][30];
int m, n, k, q;

int aroundSum(int x, int y) {
	int u, v, w;
	u = a[x - 1][y - 1] + a[x - 1][y] + a[x - 1][y + 1];
	v = a[x][y - 1] + a[x][y + 1];
	w = a[x + 1][y - 1] + a[x + 1][y] + a[x + 1][y + 1];
	return u + v + w;
}

int main() {
	cin >> m >> n >> k >> q;
	for(int i = 1; i <= k; i++) {
		int x, y, v;
		cin >> x >> y >> v;
		a[x][y] = v;
	}
	for(int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		cout << aroundSum(x, y) << endl;
	}
	return 0;
}
