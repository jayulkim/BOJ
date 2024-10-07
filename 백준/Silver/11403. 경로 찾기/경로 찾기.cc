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
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num = 0;
			cin >> num;
			if (num == 1) {
				dist[i][j] = 1;
			}
		}	
	}
	floydWarshall(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) {
				cout << 0 << ' ';
			}
			else {
				cout << 1 << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}