#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int dist[201][201];
int result[201][201];
int n = 0, m = 0;
void floydwarshall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dist[j][k] > dist[j][i] + dist[i][k]) {
					dist[j][k] = dist[j][i] + dist[i][k];
					result[j][k] = result[j][i];
				}
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
			dist[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		if (dist[start][end] > weight) {
			dist[start][end] = weight;
			result[start][end] = end;
		}
		if (dist[end][start] > weight) {
			dist[end][start] = weight;
			result[end][start] = start;
		}
	}
	floydwarshall();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				cout << '-' << ' ';
			}
			else {
				cout << result[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}