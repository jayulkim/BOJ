#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dist[1001][1001];
ll n = 0, m = 0, k = 0;
vector<pair<pair<ll, ll>, ll>>v;
ll getdist(ll x1, ll y1, ll x2, ll y2) {
	return llabs(x1 - x2) + llabs(y1 - y2);
}
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
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				dist[i][j] = 98765432100;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		ll s = 0, x = 0, y = 0;
		cin >> s >> x >> y;
		v.push_back({ {x, y}, s });
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			ll d = getdist(v[i].first.first, v[i].first.second, v[j].first.first, v[j].first.second);
			dist[i + 1][j + 1] = d;
			dist[j + 1][i + 1] = d;
			if (v[j].second && v[i].second) {
				dist[i + 1][j + 1] = min(dist[i + 1][j + 1], m);
				dist[j + 1][i + 1] = min(dist[j + 1][i + 1], m);
			}
		}
	}
	floydwarshall();
	cin >> k;
	for (int i = 0; i < k; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		cout << dist[start][end] << '\n';
	}
	return 0;
}