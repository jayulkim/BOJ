#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool visited[100001];
vector<ll>graph[100001];
ll dist[100001];
ll result = 1;
void bfs(ll start) {
	queue<ll>q;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		ll temp = q.front();
		q.pop();
		visited[temp] = true;
		dist[temp] = result++;
		for (auto& i : graph[temp]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), greater<ll>());
	}
	bfs(k);
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << '\n';
	}
	return 0;
}