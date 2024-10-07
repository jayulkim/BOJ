#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0, k = 0;
int Map[251][251];
void floydwarshall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				Map[j][k] = min(Map[j][k], Map[j][i] + Map[i][k]);
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				Map[i][j] = 987654321;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0, command = 0;
		cin >> start >> end >> command;
		if (command == 0) {
			Map[start][end] = 0;
			Map[end][start] = 1;
		}
		else {
			Map[start][end] = 0;
			Map[end][start] = 0;
		}
	}
	floydwarshall();
	cin >> k;
	for (int i = 0; i < k; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		cout << Map[start][end] << '\n';
	}
	return 0;
}