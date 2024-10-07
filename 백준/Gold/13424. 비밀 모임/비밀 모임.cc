#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
ll dist[101][101];
void floydwarshall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
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
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					dist[i][j] = 987654321;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			ll start = 0, end = 0, weight = 0;
			cin >> start >> end >> weight;
			dist[start][end] = weight;
			dist[end][start] = weight;
		}
		floydwarshall();
		ll k = 0;
		cin >> k;
		vector<ll>ary(k);
		for (int i = 0; i < k; i++) {
			cin >> ary[i];
		}
		vector<pair<ll, ll>>v;
		for (int i = 1; i <= n; i++) {
			ll sum = 0;
			for (auto& j : ary) {
				if (i != j) {
					sum += dist[j][i];
				}
			}
			v.push_back({ sum, i });
		}
		sort(v.begin(), v.end());
		cout << v[0].second << '\n';
	}
	return 0;
}