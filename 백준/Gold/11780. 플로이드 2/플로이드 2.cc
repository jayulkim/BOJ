#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dist[101][101];
int Next[101][101];
int n = 0, m = 0;
vector<int>v;
void getNext(int start, int end) {
	if (start == end) {
		return;
	}
	v.push_back(Next[start][end]);
	getNext(Next[start][end], end);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				dist[i][j] = 987654321;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		dist[start][end] = min(dist[start][end], weight);
		Next[start][end] = end;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j != k && dist[j][k] > dist[j][i] + dist[i][k]) {
					dist[j][k] = dist[j][i] + dist[i][k];
					Next[j][k] = Next[j][i];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == 987654321) {
				cout << 0 << ' ';
			}
			else {
				cout << dist[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == 987654321 || i == j) {
				cout << 0 << '\n';
			}
			else {
				v.push_back(i);
				getNext(i, j);
				cout << v.size() << ' ';
				for (auto& k : v) {
					cout << k << ' ';
				}
				vector<int>().swap(v);
				cout << '\n';
			}
		}
	}
	return 0;
}