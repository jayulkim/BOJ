#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<vector<ll>>dist;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	ll count = 1;
	cin >> num;
	while (num--) {
		cin >> n >> m >> k;
		vector<pll>v;
		for (int i = 0; i < m; i++) {
			ll a = 0, b = 0;
			cin >> a >> b;
			v.push_back({ a, b });
		}
		vector<vector<pll>>graph(n + 1, vector<pll>());
		vector<vector<ll>>(m, vector<ll>(n + 1, LLONG_MAX)).swap(dist);
		for (int i = 0; i < k; i++) {
			ll a = 0, b = 0;
			cin >> a >> b;
			vector<ll>temp;
			for (int j = 0; j < b; j++) {
				ll aa = 0;
				cin >> aa;
				temp.push_back(aa);
			}
			for (int j = 0; j < temp.size() - 1; j++) {
				graph[temp[j]].push_back({ a, temp[j + 1] });
				graph[temp[j + 1]].push_back({ a, temp[j] });
			}
		}
		ll Min = LLONG_MAX;
		for (int i = 0; i < v.size(); i++) {
			dist[i][v[i].first] = 0;
			priority_queue<pll, vector<pll>, greater<pll>>pq;
			pq.push({ 0, v[i].first});
			while (!pq.empty()) {
				pll temp = pq.top();
				pq.pop();
				if (dist[i][temp.second] >= temp.first) {
					for (auto& j : graph[temp.second]) {
						if (dist[i][j.second] > dist[i][temp.second] + j.first) {
							dist[i][j.second] = dist[i][temp.second] + j.first;
							pq.push({ dist[i][j.second], j.second });
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			ll Max = 0;
			bool find = false;
			for (int j = 0; j < v.size(); j++) {
				if (dist[j][i] == LLONG_MAX) {
					find = true;
					break;
				}
				Max = max(Max, dist[j][i] * v[j].second);
			}
			if (!find) {
				Min = min(Min, Max);
			}
		}
		if (Min == LLONG_MAX) {
			cout << "Case #" << count++ << ": " << -1 << '\n';
		}
		else {
			cout << "Case #" << count++ << ": " << Min << '\n';
		}
	}
	return 0;
}