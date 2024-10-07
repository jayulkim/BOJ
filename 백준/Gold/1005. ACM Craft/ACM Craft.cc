#include <bits/stdc++.h>
using namespace std;
int degree[10001];
int weight[10001];
vector<int>graph[10001];
int n = 0, m = 0;
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
	int num = 0;
	cin >> num;
	while (num--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> weight[i];
		}
		for (int i = 0; i < m; i++) {
			int start = 0, end = 0;
			cin >> start >> end;
			degree[end]++;
			graph[start].push_back(end);
		}
		toposort();
		int k = 0;
		cin >> k;
		cout << result[k] << '\n';
		memset(result, 0, sizeof(result));
		for (int i = 1; i <= n; i++) {
			vector<int>().swap(graph[i]);
		}
	}
	return 0;
}