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
class Dijkstra {
private:
	using ll = long long;
	using pll = pair<ll, ll>;
	ll n;
	vector<ll>start;
	vector<vector<pll>>graph;
public:
	vector<ll>dist;
	vector<vector<pll>>revgraph;
	Dijkstra(ll n, vector<ll>start, vector<vector<pll>>&graph) {
		this->n = n;
		this->start = start;
		this->graph = graph;
	}
	vector<ll> run() {
		priority_queue<pll, vector<pll>, greater<pll>>pq;
		dist.assign(n + 1, LLONG_MAX);
		for (auto& i : start) {
			dist[i] = 0;
			pq.push({ 0, i });
		}
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
		return dist;
	}
	pair<vector<ll>, vector<vector<pll>>> revrun() {
		priority_queue<pll, vector<pll>, greater<pll>>pq;
		dist.assign(n + 1, LLONG_MAX);
		revgraph.assign(n + 1, vector<pll>());
		for (auto& i : start) {
			dist[i] = 0;
			pq.push({ 0, i });
		}
		while (!pq.empty()) {
			auto [a, b] = pq.top();
			pq.pop();
			if (dist[b] >= a) {
				for (auto& i : graph[b]) {
					if (dist[i.first] > dist[b] + i.second) {
						vector<pll>().swap(revgraph[i.first]);
						revgraph[i.first].push_back({ b, i.second });
						dist[i.first] = dist[b] + i.second;
						pq.push({ dist[i.first], i.first });
					}
					else if (dist[i.first] == dist[b] + i.second) {
						revgraph[i.first].push_back({ b, i.second });
					}
				}
			}
		}
		return { dist, revgraph };
	}
};
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
	Dijkstra dijk(n, { 0 }, graph);
	pair<vector<ll>, vector<vector<pll>>> v = dijk.revrun();
	ll sum = 0;
	for (int i = 0; i <= n; i++) {
		ll Max = 0;
		for (auto& j : v.second[i]) {
			Max = max(Max, j.second);
		}
		sum += Max;
	}
	cout << m - n << ' ' << sum;
	return 0;
}