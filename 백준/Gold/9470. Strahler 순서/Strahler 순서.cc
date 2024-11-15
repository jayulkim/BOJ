#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll degree[1001];
vector<ll>st(1001);
vector<ll>graph[1001];
vector<ll>parent[1001];
ll n = 0, m = 0, k = 0;
void toposort() {
	queue<ll>q;
	for (int i = 1; i <= m; i++) {
		if (!degree[i]) {
			q.push(i);
			st[i] = 1;
		}
	}
	for (int i = 0; i < m; i++) {
		if (!q.empty()) {
			ll temp = q.front();
			q.pop();
			vector<ll>v;
			for (auto& i : parent[temp]) {
				v.push_back(st[i]);
			}
			sort(v.begin(), v.end(), greater<ll>());
			if (v.size() > 1) {
				if (v[0] == v[1]) {
					st[temp] = v[0] + 1;
				}
				else {
					st[temp] = v[0];
				}
			}
			else if (v.size() == 1) {
				st[temp] = v[0];
			}
			for (auto& i : graph[temp]) {
				if (--degree[i] == 0) {
					q.push(i);
				}
				parent[i].push_back(temp);
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
		for (int i = 0; i < k; i++) {
			ll start = 0, end = 0;
			cin >> start >> end;
			graph[start].push_back(end);
			degree[end]++;
		}
		toposort();
		cout << n << ' ' << st[m] << '\n';
		memset(degree, 0, sizeof(degree));
		for (int i = 1; i <= m; i++) {
			vector<ll>().swap(graph[i]);
		}
		for (int i = 1; i <= m; i++) {
			vector<ll>().swap(parent[i]);
		}
	}
	return 0;
}