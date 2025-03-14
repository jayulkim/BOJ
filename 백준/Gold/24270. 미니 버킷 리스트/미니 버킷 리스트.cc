#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;
ll addmod(ll x, ll y, ll num) {
	if (x >= num - y) {	
        return x - (num - y);
    }
	return x + y;
}
ll mulmod(ll x, ll y, ll num) {
	ll result = 0;
	while (y > 0) {
		if (y % 2) {
			result = addmod(result, x, num);
		}
		x = addmod(x, x, num);
		y /= 2;
	}
	return result;
}
int main(void) { 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		sum += num;
	}
	if (sum > m) {
		cout << 0;
	}
	else {
		ll result = 1;
		for (ll i = n + m - sum; i >= m - sum + 1; i--) {
			result = mulmod(result, i, 1000000007);
		}
		cout << result;
	}
	return 0;
}