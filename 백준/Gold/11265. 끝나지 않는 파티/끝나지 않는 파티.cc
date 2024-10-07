#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dist[501][501];
ll n = 0, m = 0;
void floydwarshall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
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
			cin >> dist[i][j];
		}
	}
	floydwarshall();
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		if (start == end) {
			cout << "Enjoy other party" << '\n';
		}
		else {
			if (dist[start][end] <= weight) {
				cout << "Enjoy other party" << '\n';
			}
			else {
				cout << "Stay here" << '\n';
			}
		}
	}
	return 0;
}