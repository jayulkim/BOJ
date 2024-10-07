#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll visited[100001];
ll depth[100001];
int n = 0, m = 0, k = 0;
vector<int>graph[100001];
void bfs(int start) {
	ll count = 1;
	depth[start] = 0;
	visited[start] = count;
	queue<int>q;
	q.push(start);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		visited[temp] = count;
		count++;
		for (auto& i : graph[temp]) {
			if (depth[i] == -1) {		
				depth[i] = depth[temp] + 1;
				q.push(i);
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		depth[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	bfs(k);
	ll result = 0;
	for (int i = 1; i <= n; i++) {
		result += (depth[i] * visited[i]);
	}
	cout << result;
	return 0;
}