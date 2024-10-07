#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;
ll dist[51][51];
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
	while (1) {
		int start = 0, end = 0;
		cin >> start >> end;
		if (start == -1 && end == -1) {
			break;
		}
		dist[start][end] = 1;
		dist[end][start] = 1;
	}
	floydWarshall(n);
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++) {
		ll Max = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				Max = max(Max, dist[i][j]);
			}
		}
		v[i] = Max;
	}
	int Min = INF;
	for (int i = 1; i <= n; i++) {
		Min = min(Min, v[i]);
	}
	int count = 0;
	vector<int>idx;
	for (int i = 1; i <= n; i++) {
		if (v[i] == Min) {
			count++;
			idx.push_back(i);
		}
	}
	cout << Min << ' ' << count << '\n';
	for (auto& i : idx) {
		cout << i << ' ';
	}
	return 0;
}