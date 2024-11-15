#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
map<ll, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	ll Min = LLONG_MAX;
	if (m < k) {
		swap(m, k);
	}
	for (int i = 0; i <= n / m + 1; i++) {
		ll temp = m * i + ((n - m * i + k - 1) / k) * k;
		if (Map[temp]) {
			break;
		}
		Map[temp]++;
		Min = min(temp, Min);
	}
	cout << Min;
	return 0;
}