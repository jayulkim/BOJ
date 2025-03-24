#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;
vector<ll>v[101];
vector<lll>graph[101][101];
vector<vector<ll>>dist(101, vector<ll>(101, LLONG_MAX));
void dijkstra(ll start) {
	dist[start][0] = 0;
	priority_queue<lll, vector<lll>, greater<lll>>pq;
	pq.push({ 0, start, 0 });
	while (!pq.empty()) {
		auto [a, b, c] = pq.top();
		pq.pop();
		if (dist[b][c] >= a) {
			for (auto& [aa, bb, cc] : graph[b][c]) {
				if (dist[bb][cc] > dist[b][c] + aa) {
					dist[bb][cc] = dist[b][c] + aa;
					pq.push({ dist[bb][cc], bb, cc });
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	v[0].push_back(1);
	for (int i = 1; i <= n; i++) {
		ll a = 0, b = 0;
		cin >> a;
		for (int j = 0; j < a; j++) {
			ll num = 0;
			cin >> num;
			v[i].push_back(num);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			for (int k = 0; k < v[i + 1].size(); k++) {
				if (v[i][j] + 1 == v[i + 1][k] || v[i][j] - 1 == v[i + 1][k] || (min((ll)20, v[i][j] * 2) == v[i + 1][k]) || v[i][j] == v[i + 1][k]) {
					graph[i][j].push_back({0, i + 1, k});
				}
				else {
					graph[i][j].push_back({1, i + 1, k});
				}
			}
		}
	}
	dijkstra(0);
	ll Min = LLONG_MAX;
	for (auto& i : dist[n]) {
		Min = min(Min, i);
	}
	if (Min > m) {
		cout << -1;
		return 0;
	}
	cout << Min;
	return 0;
}