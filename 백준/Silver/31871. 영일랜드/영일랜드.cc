#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0;
int dist[10][10];
int Max = 0;
vector<int>result;
bool visited[10];
bool Find = false;
void dfs() {
	if (result.size() == n + 1) {
		result.push_back(0);
		int count = 0;
		for (int i = 0; i <= n; i++) {
			if (!dist[result[i]][result[i + 1]]) {
				result.pop_back();
				return;
			}
			count += dist[result[i]][result[i + 1]];
		}
		Find = true;
		Max = max(Max, count);
		result.pop_back();
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			result.push_back(i);
			visited[i] = true;
			dfs();
			visited[i] = false;
			result.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		dist[start][end] = max(dist[start][end], weight);
	}
	result.push_back(0);
	dfs();
	if (!Find) {
		cout << -1;
		return 0;
	}
	cout << Max;
	return 0;
}