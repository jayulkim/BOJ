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
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), greater<ll>());
	}
	priority_queue<pll>pq;
	ll sum = 0;
	vector<pll>vv;
	for (int i = 1; i <= n; i++) {
		if (!graph[i].empty()) {
			vv.push_back({ graph[i].back(), i });
			graph[i].pop_back();
		}
	}
	for (int i = 1; i <= n; i++) {
		vector<pll>vvv;
		for (auto& j : vv) {
			sum += j.first;
			pq.push(j);
			if (!graph[j.second].empty()) {
				vvv.push_back({ graph[j.second].back(), j.second });
				graph[j.second].pop_back();
			}
		}
		vector<pll>().swap(vv);
		for (auto& j : vvv) {
			vv.push_back(j);
		}
		if (pq.size() < m) {
			cout << -1 << ' ';
			continue;
		}
		while (pq.size() > m) {
			pll temp = pq.top();
			pq.pop();
			sum -= temp.first;
		}
		cout << sum << ' ';
	}
	return 0;
}