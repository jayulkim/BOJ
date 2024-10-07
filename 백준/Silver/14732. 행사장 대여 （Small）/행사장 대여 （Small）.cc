#include <bits/stdc++.h>
using namespace std;
int Map[501][501];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		int starty = 0, startx = 0, endy = 0, endx = 0;
		cin >> starty >> startx >> endy >> endx;
		for (int j = starty; j < endy; j++) {
			for (int k = startx; k < endx; k++) {
				Map[j][k] = 1;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++) {
			sum += Map[i][j];
		}
	}
	cout << sum;
	return 0;
}