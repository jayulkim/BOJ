#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
	vector<pll>v(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i].second;
	}
	vector<vector<ll>>graph(n + 1);
	for (int i = 0; i < n; i++) {
		graph[v[i].first].push_back(v[i].second);
	}
	for (int i = 0; i < n; i++) {
		sort(graph[i].begin(), graph[i].end(), greater<ll>());
	}
	priority_queue<pll>pqpq;
	ll sum = 0;
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	for (int i = 1; i <= n; i++) {
		if (!graph[i].empty()) {
			pq.push({ graph[i].back(), i });
			graph[i].pop_back();
		}
	}
	for (int i = 1; i <= n; i++) {
		vector<pll>vv;
		while (!pq.empty() && pqpq.size() < m) {
			pll temp = pq.top();
			pq.pop();
			sum += temp.first;
			pqpq.push(temp);
			if (!graph[temp.second].empty()) {
				vv.push_back({ graph[temp.second].back(), temp.second });
				graph[temp.second].pop_back();
			}
		}
		for (auto& j : vv) {
			pq.push(j);
		}
		if (pqpq.size() < m) {
			cout << -1 << ' ';
		}
		else {
			cout << sum << ' ';
			vector<pll>vv;
			vector<pll>vvv;
			while (!pq.empty() && !pqpq.empty() && pq.top().first < pqpq.top().first) {
				pll a = pq.top();
				pll b = pqpq.top();
				pq.pop();
				pqpq.pop();
				sum -= b.first;
				sum += a.first;
				vv.push_back(a);
				if (!graph[a.second].empty()) {
					vvv.push_back({ graph[a.second].back(), a.second });
					graph[a.second].pop_back();
				}
			}
			for (auto& j : vv) {
				pqpq.push(j);
			}
			for (auto& j : vvv) {
				pq.push(j);
			}
		}
	}
	return 0;
}