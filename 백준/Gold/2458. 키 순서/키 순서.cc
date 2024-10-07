#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;
ll dist[501][501];
void floydWarshall(int n) {
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
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		dist[start][end] = 1;
	}
	floydWarshall(n);
	int result = 0;
	for (int i = 1; i <= n; i++) {
		int count = 0;
		for (int j = 1; j <= n; j++) {
			if ((dist[i][j] != INF || dist[j][i] != INF) && i != j) {
				count++;
			}
		}
		if (count == n - 1) {
			result++;
		}
	}
	cout << result;
	return 0;
}