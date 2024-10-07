#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[100001];
vector<ll>tree[100001];
bool visited[100001];
ll cost[100001];
void graphbfs(ll start) {
	visited[start] = true;
	queue<ll>q;
	q.push(start);
	while (!q.empty()) {
		ll temp = q.front();
		q.pop();
		visited[temp] = true;
		for (auto& i : graph[temp]) {
			if (!visited[i]) {
				tree[temp].push_back(i);
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
void treedfs(ll start, ll x) {
	if (x <= cost[start]) {
		cost[start] += x;
		return;
	}
	else {
		x -= cost[start];
		cost[start] += cost[start];
		for (auto& i : tree[start]) {
			treedfs(i, x / tree[start].size());
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	graphbfs(1);
	for (int i = 0; i < m; i++) {
		ll command = 0, u = 0, x = 0;
		cin >> command;
		if (command == 1) {
			cin >> u >> x;
			treedfs(u, x);
		}
		else {
			cin >> u;
			cout << cost[u] << '\n';
		}
	}
	return 0;
}