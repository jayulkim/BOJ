#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll s = 0, g = 0, h = 0;
vector<pll>graph[2001];
vector<ll>dists(2001, LLONG_MAX);
vector<ll>distg(2001, LLONG_MAX);
vector<ll>disth(2001, LLONG_MAX);
priority_queue<pll, vector<pll>, greater<pll>>pq;
void dijkstra(ll start, vector<ll>&dist) {
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
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n >> m >> k;
		cin >> s >> g >> h;
		ll cost = 0;
		for (int i = 0; i < m; i++) {
			ll start = 0, end = 0, weight = 0;
			cin >> start >> end >> weight;
			graph[start].push_back({ weight, end });
			graph[end].push_back({ weight, start });
			if ((start == g && end == h) || (end == g && start == h)) {
				cost = weight;
			}
		}
		dijkstra(s, dists);
		dijkstra(g, distg);
		dijkstra(h, disth);
		vector<ll>result;
		for (int i = 0; i < k; i++) {
			ll num = 0;
			cin >> num;
			if (disth[s] + distg[num] + cost == dists[num] || distg[s] + disth[num] + cost == dists[num]) {
				result.push_back(num);
			}
		}
		sort(result.begin(), result.end());
		for (auto& i : result) {
			cout << i << ' ';
		}
		cout << '\n';
		vector<ll>(2001, LLONG_MAX).swap(dists);
		vector<ll>(2001, LLONG_MAX).swap(distg);
		vector<ll>(2001, LLONG_MAX).swap(disth);
		for (int i = 1; i <= n; i++) {
			vector<pll>().swap(graph[i]);
		}
	}
	return 0;
}