#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
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
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = 987654321;
		}
	}
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	floydwarshall();
	ll Min = LLONG_MAX, a = 0, b = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			ll sum = 0;
			for (int k = 1; k <= n; k++) {
				if (k != i && k != j) {
					sum += (2 * min(dist[k][i], dist[k][j]));
				}
			}
			if (sum < Min) {
				Min = sum;
				a = i;
				b = j;
			}
		}
	}
	cout << a << ' ' << b << ' ' << Min;
	return 0;
}