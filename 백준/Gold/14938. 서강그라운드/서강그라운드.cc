#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;
ll dist[101][101];
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
	int n = 0, k = 0, m = 0;
	cin >> n >> k >> m;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				dist[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		dist[start][end] = weight;
		dist[end][start] = weight;
	}
	floydWarshall(n);
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[j][i] <= k) {
				sum += v[j];
			}
		}
		Max = max(Max, sum);
	}
	cout << Max;
	return 0;
}