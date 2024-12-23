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
	cin >> n;
	ll Max = 0, Min = LLONG_MAX;
	ll result = 0;
	for (int i = 1; i <= n; i++) {
		ll num = 0;
		cin >> num;
		Max = max(Max, min(num, (ll)i));
		Min = min(Min, max(num, (ll)i));
		result += llabs(num - i);
	}
	cout << result + 2 * max((ll)0, Max - Min);
	return 0;
}