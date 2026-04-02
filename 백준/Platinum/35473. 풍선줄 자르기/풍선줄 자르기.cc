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
	cin >> n >> m;
	vector<vector<pll>>graph(n + 1);
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	vector<vector<pll>>digraph(n + 1);
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	vector<ll>dist(n + 1, LLONG_MAX);
	vector<ll>redist(n + 1, LLONG_MAX);
	pq.push({ 0, 0 });
	dist[0] = 0;
	while (!pq.empty()) {
		auto [a, b] = pq.top();
		pq.pop();
		if (dist[b] >= a) {
			for (auto& i : graph[b]) {
				if (dist[i.first] > dist[b] + i.second) {
					vector<pll>().swap(digraph[i.first]);
					digraph[i.first].push_back({ b, i.second });
					dist[i.first] = dist[b] + i.second;
					pq.push({ dist[i.first], i.first });
				}
				else if (dist[i.first] == dist[b] + i.second) {
					digraph[i.first].push_back({ b, i.second });
				}
			}
		}
	}
	ll sum = 0;
	for (int i = 0; i <= n; i++) {
		ll Max = 0;
		for (auto& j : digraph[i]) {
			Max = max(Max, j.second);
		}
		sum += Max;
	}
	cout << m - n << ' ' << sum;
	return 0;
}