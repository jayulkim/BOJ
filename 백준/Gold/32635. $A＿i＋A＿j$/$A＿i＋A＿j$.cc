#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	ll s = 0, t = 0;
	cin >> s >> t;
	vector<vector<pll>>graph(n + 1);
	vector<vector<pll>>regraph(n + 1);
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		regraph[b].push_back({ a, c });
	}
	vector<ll>dist(n + 1, 1e18);
	vector<ll>redist(n + 1, 1e18);
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	dist[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		auto [a, b] = pq.top();
		pq.pop();
		if (dist[b] >= a) {
			for (auto& i : graph[b]) {
				if (dist[i.first] > dist[b] + i.second) {
					dist[i.first] = dist[b] + i.second;
					pq.push({ dist[i.first], i.first });
				}
			}
		}
	}
	redist[t] = 0;
	pq.push({ 0, t });
	while (!pq.empty()) {
		auto [a, b] = pq.top();
		pq.pop();
		if (redist[b] >= a) {
			for (auto& i : regraph[b]) {
				if (redist[i.first] > redist[b] + i.second) {
					redist[i.first] = redist[b] + i.second;
					pq.push({ redist[i.first], i.first });
				}
			}
		}
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(3, -1));
	function<ll(ll, ll)> dfs = [&](ll a, ll b) -> ll {
		if (b == 2) {
			return 0;
		}
		if (a == t) {
			if (b == 1) {
				return v[a];
			}
			return 1e18;
		}
		if (dp[a][b] != -1) {
			return dp[a][b];
		}
		ll weight = 1e18;
		for (auto& i : graph[a]) {
			if (dist[a] + redist[i.first] + i.second == dist[t]) {
				weight = min({ weight, dfs(i.first, b), dfs(i.first, b + 1) + v[a] });
			}
		}
		return dp[a][b] = weight;
		};
	ll result = dfs(s, 0);
	if (result == 1e18) {
		cout << -1;
		return 0;
	}
	cout << result;
	return 0;
}