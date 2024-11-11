#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
vector<pll>graph[200001];
priority_queue<pll, vector<pll>, greater<pll>>pq;
ll dist[200001];
ll n = 0, m = 0, k = 0;
void dijkstra(ll start) {
	for (int i = 1; i <= n; i++) {
		dist[i] = LLONG_MAX;
	}
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		pll temp = pq.top();
		pq.pop();
		if (dist[temp.second] >= temp.first) {
			for (auto& i : graph[temp.second]) {
				if (dist[i.second] > dist[temp.second] + i.first) {
					dist[i.second] = dist[temp.second] + i.first;
					pq.push({ dist[i.second], i.second });
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back({ weight, end });
		graph[end].push_back({ weight, start });
	}
	dijkstra(1);
	ll a = 0;
	cin >> a;
	vector<ll>v;
	for (int i = 0; i < a; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	ll Min = LLONG_MAX;
	for (int i = 0; i < a; i++) {
		ll temp = k - 1 + (k * i);
		if (dist[v[i]] <= temp) {
			Min = min(Min, max(dist[v[i]], temp - (k - 1)));
		}
		else {
			Min = min(Min, max(((dist[v[i]] - temp + (a * k) - 1) / (a * k)) * (a * k) + temp - (k - 1), dist[v[i]]));
		}
	}
	cout << Min;
	return 0;
}