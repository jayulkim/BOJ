#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0, k = 0;
vector<int>graph[100001];
int visited[100001];
int result = 1;
void dfs(int start) {
	visited[start] = result++;
	for (auto& i : graph[start]) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
		reverse(graph[i].begin(), graph[i].end());
	}
	dfs(k);
	for (int i = 1; i <= n; i++) {
		cout << visited[i] << '\n';
	}
	return 0;
}