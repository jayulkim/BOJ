#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
vector<ll>v(1000001);
vector<ll>sum(1000001);
vector<tp>vv;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + v[i];
	}
	for (int i = 0; i < m + k; i++) {
		ll a = 0, b = 0, c = 0, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			vv.push_back({ b, c, d });
		}
		else {
			cin >> b >> c;
			ll result = sum[c] - sum[b - 1];
			for (auto [e, f, g] : vv) {
				if (b > f || c < e) {
					continue;
				}
				result += ((min(c, f) - max(b, e) + 1) * g);
			}
			cout << result << '\n';
		}
	}
	return 0;
}