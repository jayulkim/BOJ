#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
ll a = 0, b = 0;
vector<ll>graph[101];
bool visited[101];
bool Find = false;
void dfs(ll start, ll count) {
	if (start == b) {
		cout << count;
		Find = true;
		return;
	}
	visited[start] = true;
	for (auto& i : graph[start]) {
		if (!visited[i]) {
			dfs(i, count + 1);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> a >> b;
	cin >> m;
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	dfs(a, 0);
	if (!Find) {
		cout << -1;
	}
	return 0;
}