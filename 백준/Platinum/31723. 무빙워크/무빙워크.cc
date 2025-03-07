#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;
vector<ll>dist(300001, LLONG_MAX);
priority_queue<pll, vector<pll>, greater<pll>>pq;
vector<lll>graph[300001];
vector<ll>v(500001, 0);
map<pll, ll>Map;
void dijkstra(ll start) {
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		pll temp = pq.top();
		pq.pop();
		if (dist[temp.second] >= temp.first) {
			for (auto [a, b, c] : graph[temp.second]) {
				if (dist[b] > dist[temp.second] + a) {
					dist[b] = dist[temp.second] + a;
					pq.push({ dist[b], b });
					if (c) {
						v[Map[{temp.second, b}]] = 1;
					}
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll idx = 0;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back({ c, b, 1 });
		graph[b].push_back({ 2 * c, a, 0 });
		Map[{a, b}] = idx++;
	}
	dijkstra(1);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += dist[i];
	}
	cout << sum << '\n';
	for (int i = 0; i < m; i++) {
		cout << v[i] << ' ';
	}
	return 0;
}