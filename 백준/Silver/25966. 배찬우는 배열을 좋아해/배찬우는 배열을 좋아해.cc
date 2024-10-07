#include <bits/stdc++.h>
using namespace std;
int Map[3001][3001];
int yy[3001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		yy[i] = i;
	}
	for (int i = 0; i < k; i++) {
		int command = 0, y = 0, x = 0, num = 0;
		cin >> command;
		if (command == 0) {
			cin >> y >> x >> num;
			Map[yy[y]][x] = num;
		}
		else {
			cin >> y >> x;
			swap(yy[y], yy[x]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << Map[yy[i]][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}