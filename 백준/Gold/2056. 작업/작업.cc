#include <bits/stdc++.h>
using namespace std;
int degree[10001];
int weight[10001];
vector<int>graph[10001];
int n = 0;
int result[10001];
int solve = 0;
void toposort() {
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) {
			q.push(i);
			result[i] = weight[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (!q.empty()) {
			int temp = q.front();
			q.pop();
			for (auto& i : graph[temp]) {
				if (--degree[i] == 0) {
					q.push(i);
				}
				result[i] = max(result[i], result[temp] + weight[i]);
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int m = 0;
		cin >> weight[i] >> m;
		degree[i] = m;
		for (int j = 0; j < m; j++) {
			int end = 0;
			cin >> end;
			graph[end].push_back(i);
		}
	}
	toposort();
	for (int i = 1; i <= n; i++) {
		solve = max(solve, result[i]);
	}
	cout << solve;
	return 0;
}