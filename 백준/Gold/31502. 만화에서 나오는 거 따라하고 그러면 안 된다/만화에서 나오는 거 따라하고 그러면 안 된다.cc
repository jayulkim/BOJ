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
	ll aa = 0, bb = 0, cc = 0;
	cin >> aa >> bb >> cc;
	vector<vector<pll>>dijkgraph(n + 1);
	vector<vector<pll>>graph(n + 1);
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		dijkgraph[a].push_back({ b, 1 });
		dijkgraph[b].push_back({ a, 1 });
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	vector<ll>dijkdist(n + 1, LLONG_MAX);
	vector<ll>reversedijkdist(n + 1, LLONG_MAX);
	vector<ll>dist(n + 1, LLONG_MAX);
	priority_queue<pll, vector<pll>, greater<pll>>dijkpq;
	priority_queue<pll, vector<pll>, greater<pll>>reversedijkpq;
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	dijkpq.push({ 0, bb });
	dijkdist[bb] = 0;
	while (!dijkpq.empty()) {
		pll temp = dijkpq.top();
		dijkpq.pop();
		if (dijkdist[temp.second] >= temp.first) {
			for (auto& i : dijkgraph[temp.second]) {
				if (dijkdist[i.first] > dijkdist[temp.second] + i.second) {
					dijkdist[i.first] = dijkdist[temp.second] + i.second;
					dijkpq.push({ dijkdist[i.first], i.first });
				}
			}
		}
	}
	reversedijkpq.push({ 0, cc });
	reversedijkdist[cc] = 0;
	while (!reversedijkpq.empty()) {
		pll temp = reversedijkpq.top();
		reversedijkpq.pop();
		if (reversedijkdist[temp.second] >= temp.first) {
			for (auto& i : dijkgraph[temp.second]) {
				if (reversedijkdist[i.first] > reversedijkdist[temp.second] + i.second) {
					reversedijkdist[i.first] = reversedijkdist[temp.second] + i.second;
					reversedijkpq.push({ reversedijkdist[i.first], i.first });
				}
			}
		}
	}
	queue<lll>q;
	q.push({ bb, 0, 0 });
	vector<bool>visited(n + 1, false);
	visited[bb] = true;
	vector<pll>step(n + 1, {0, 0});
	while (!q.empty()) {
		auto [a, b, c] = q.front();
		q.pop();
		visited[a] = true;
		step[c] = max(step[c], { b, a });
		if (a == cc) {	
			break;
		}
		pll Max = { 0, 0 };
		for (auto& i : dijkgraph[a]) {
			if (dijkdist[cc] == reversedijkdist[i.first] + dijkdist[a] + i.second && !visited[i.first]) {
				Max = max(Max, { dijkgraph[i.first].size(), i.first });
			}
		}
		q.push({ Max.second, Max.first, c + 1 });
		visited[Max.second] = true;
	}
	map<ll, ll>Map;
	for (int i = 0; i < n; i++) {
		if (step[i].second) {
			Map[step[i].second]++;
		}
	}
	pq.push({ 0, aa });
	dist[aa] = 0;
	while (!pq.empty()) {
		pll temp = pq.top();
		pq.pop();
		if (dist[temp.second] >= temp.first) {
			for (auto& i : graph[temp.second]) {
				if (dist[i.first] > dist[temp.second] + i.second) {
					dist[i.first] = dist[temp.second] + i.second;
					pq.push({ dist[i.first], i.first });
				}
			}
		}
	}
	pll Min = { LLONG_MAX, LLONG_MAX };
	for (int i = 1; i <= n; i++) {
		if (Map[i]) {
			Min = min(Min, { dist[i], i });
		}
	}
	cout << Min.second;
	return 0;
}