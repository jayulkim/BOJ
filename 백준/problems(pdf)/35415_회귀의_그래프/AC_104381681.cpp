#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t = 0;
	cin >> n >> m >> k >> t;
	vector<vector<pll>>graph(n + 1);
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	vector<ll>dist(n + 1, 1e12);
	vector<ll>redist(n + 1, 1e12);
	vector<ll>kdist(n + 1, 1e12);
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	dist[1] = 0;
	pq.push({ 0, 1 });
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
	redist[n] = 0;
	pq.push({ 0, n });
	while (!pq.empty()) {
		auto [a, b] = pq.top();
		pq.pop();
		if (redist[b] >= a) {
			for (auto& i : graph[b]) {
				if (redist[i.first] > redist[b] + i.second) {
					redist[i.first] = redist[b] + i.second;
					pq.push({ redist[i.first], i.first });
				}
			}
		}
	}
	kdist[k] = 0;
	pq.push({ 0, k });
	while (!pq.empty()) {
		auto [a, b] = pq.top();
		pq.pop();
		if (kdist[b] >= a) {
			for (auto& i : graph[b]) {
				if (kdist[i.first] > kdist[b] + i.second) {
					kdist[i.first] = kdist[b] + i.second;
					pq.push({ kdist[i.first], i.first });
				}
			}
		}
	}
	ll result = 1e12;
	result = min(result, dist[k] + redist[k]);
	for (int i = 1; i <= n; i++) {
		if (dist[i] + kdist[i] >= t && kdist[i] <= t) {
			result = min(result, dist[i] + t + redist[i]);
		}
	}
	if (result == 1e12) {
		result = -1;
	}
	cout << result;
	return 0;
}