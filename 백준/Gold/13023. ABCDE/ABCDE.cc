#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
bool visited[2001];
vector<ll>graph[2001];
bool Find = false;
void dfs(ll start, ll depth) {
	if (depth == 5) { 
		Find = true;
		return;
	}
	for (auto& i : graph[start]) {
		if (!visited[i]) {
			visited[start] = true;
			dfs(i, depth + 1);
			visited[i] = false;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 0; i < n; i++) {
		visited[i] = true;
		dfs(i, 1);
		if (Find) {
			cout << 1;
			return 0;
		}
		memset(visited, false, sizeof(visited));
	}
	cout << 0;
	return 0;
}