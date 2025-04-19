#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll> lll;
typedef tuple<pll, string, ll> pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<vector<ll>>graph(n + 1);
	vector<vector<ll>>topograph(n + 1);
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	vector<ll>visited(n + 1, 0);
	ll id = 0;
	vector<ll>Map(n + 1, 0);
	ll Mapid = 0;
	vector<bool>finished(n + 1, false);
	vector<ll>indegree(n + 1, 0);
	vector<ll>outdegree(n + 1, 0);
	vector<ll>s;
	function<ll(ll)> dfs = [&](ll start) -> ll {
		visited[start] = ++id;
		ll parent = visited[start];
		s.push_back(start);
		for (auto& i : graph[start]) {
			if (!visited[i]) {
				parent = min(parent, dfs(i));
			}
			else if (!finished[i]) {
				parent = min(parent, visited[i]);
			}
		}
		if (parent == visited[start]) {
			Mapid++;
			while (1) {
				ll temp = s.back();
				s.pop_back();
				Map[temp] = Mapid;
				finished[temp] = true;
				if (start == temp) {
					break;
				}
			}
		}
		return parent;
		};
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto& j : graph[i]) {
			if (Map[i] != Map[j]) {
				topograph[Map[i]].push_back(Map[j]);
				indegree[Map[j]]++;
				outdegree[Map[i]]++;
			}
		}
	}
	if (Mapid == 1) {
		cout << 0;
		return 0;
	}
	ll a = 0, b = 0;
	for (int i = 1; i <= Mapid; i++) {
		if (!indegree[i]) {
			a++;
		}
		if (!outdegree[i]) {
			b++;
		}
	}
	cout << max(a, b);
	return 0;
}