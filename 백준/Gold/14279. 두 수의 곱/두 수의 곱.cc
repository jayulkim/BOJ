#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	ll Min = LLONG_MAX;
	for (ll i = 1; i * i <= k + n + m + k - 3; i++) {
		Min = min({ Min, llabs(n - (max((ll)1, k / i))) + llabs(m - i) + llabs(k - i * (max((ll)1, k / i))), llabs(m - (max((ll)1, k / i))) + llabs(n - i) + llabs(k - i * (max((ll)1, k / i))), llabs(n - (max((ll)1, k / i + 1))) + llabs(m - i) + llabs(k - i * (max((ll)1, k / i + 1))), llabs(m - (max((ll)1, k / i + 1))) + llabs(n - i) + llabs(k - i * (max((ll)1, k / i + 1))) });
	}
	cout << Min;
	return 0;
}