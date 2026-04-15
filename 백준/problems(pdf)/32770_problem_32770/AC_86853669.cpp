#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<string, string, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
unordered_map<string, ll>Map;
vector<pll>graph[210001];
priority_queue<pll, vector<pll>, greater<pll>>pq;
vector<ll>dist(210001, LLONG_MAX);
ll cnt = 3;
void dijkstra(ll start) {
	fill(dist.begin(), dist.end(), LLONG_MAX);
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		pll temp = pq.top();
		pq.pop();
		if (dist[temp.second] >= temp.first) {
			for (auto& i : graph[temp.second]) {
				if (dist[i.second] >= dist[temp.second] + i.first) {
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
	cin >> n;
	vector<tp>v;
	Map["sasa"] = 1;
	Map["home"] = 2;
	for (int i = 0; i < n; i++) {
		string start = "", end = "";
		ll weight = 0;
		cin >> start >> end >> weight;
		v.push_back(make_tuple(start, end, weight));
		if (!Map[start]) {
			Map[start] = cnt++;
		}
		if (!Map[end]) {
			Map[end] = cnt++;
		}
	}
	for (auto& [a, b, c] : v) {
		graph[Map[a]].push_back({ c, Map[b] });
	}
	ll result = 0;
	dijkstra(1);
	if (dist[2] == LLONG_MAX) {
		cout << -1;
		return 0;
	}
	result += dist[2];
	dijkstra(2);
	if (dist[1] == LLONG_MAX) {
		cout << -1;
		return 0;
	}
	result += dist[1];
	cout << result;
	return 0;
}