#include <bits/stdc++.h>
using namespace std;
int degree[1001];
vector<int>graph[1001];
int n = 0, m = 0;
int result[1001];
void toposort() {
	queue<pair<int, int>>q;
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) {
			q.push({i, 1});
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!q.empty()) {
			pair<int, int>temp = q.front();
			q.pop();
			result[temp.first] = temp.second;
			for (auto& i : graph[temp.first]) {
				if (--degree[i] == 0) {
					q.push({i, temp.second + 1});
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		degree[end]++;
	}
	toposort();
	for (int i = 1; i <= n; i++) {
		cout << result[i] << ' ';
	}
	return 0;
}