#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[10001];
vector<vector<ll>>scc;
ll id = 0;
ll visited[10001];
ll finished[10001];
vector<ll>s;
ll dfs(ll start) {
	visited[start] = ++id;
	s.push_back(start);
	ll parent = visited[start];
	for (auto& i : graph[start]) {
		if (!visited[i]) {
			parent = min(parent, dfs(i));
		}
		else if (!finished[i]) {
			parent = min(parent, visited[i]);
		}
	}
	if (parent == visited[start]) {
		vector<ll>v;
		while (1) {
			ll temp = s.back();
			s.pop_back();
			v.push_back(temp);
			finished[temp] = true;
			if (temp == start) {
				break;
			}
		}
		scc.push_back(v);
	}
	return parent;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	cout << scc.size() << '\n';
	for (auto& i : scc) {
		sort(i.begin(), i.end());
	}
	sort(scc.begin(), scc.end());
	for (auto& i : scc) {
		for (auto& j : i) {
			cout << j << ' ';
		}
		cout << -1 << '\n';
	}
	return 0;
}