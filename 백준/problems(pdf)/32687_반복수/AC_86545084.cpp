#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
map<ll, ll>Map;
ll mypow(ll x, ll y) {
	ll result = 1;
	for (int i = 1; i <= y; i++) {
		result *= x;
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a = "", b = "";
	cin >> a >> b >> n >> m;
	ll result = 0;
	ll end = stoll(b);
	ll start = stoll(a);
	for (ll i = mypow(10, n - 1); i < mypow(10, n); i++) {
		ll str = i;
		string t = to_string(i);
		ll idx = 0;
		while (str <= end) {
			if (str <= end) {
				if (str % m == 0 && str >= start) {
					result++;
				}
			}
			else if (str > end) {
				break;
			}
			str *= 10;
			str += (t[idx % t.length()] - '0');
			idx++;
		}
	}
	cout << result;
	return 0;
}