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
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n;
		vector<ll>result;
		ll Min = LLONG_MAX;
		ll idx = -1;
		if (n == 1) {
			cout << '\n';
		}
		else if (n == 2) {
			cout << 'B' << '\n';
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (n - i < i) {
					break;
				}
				ll a = n - i;
				ll b = i;
				ll c = 0;
				ll temp = a % b;
				c += (a / b);
				while (temp > 0) {
					a = b;
					b = temp;
					temp = a % b;
					if (a < b) {
						swap(a, b);
					}
					c += (a / b);
				}
				if (b == 1) {
					if (Min > c) {
						idx = i;
						Min = c;
					}
				}
			}
			ll a = n - idx;
			ll b = idx;
			ll c = 0;
			ll temp = a % b;
			result.push_back(a / b);
			while (temp > 0) {
				a = b;
				b = temp;
				temp = a % b;
				if (a < b) {
					swap(a, b);
				}
				result.push_back(a / b);
			}
			result.back()--;
			ll count = 0;
			for (int j = result.size() - 1; j >= 0; j--) {
				if (count % 2 == 0) {
					for (int k = 0; k < result[j]; k++) {
						cout << 'B';
					}
				}
				else {
					for (int k = 0; k < result[j]; k++) {
						cout << 'R';
					}
				}
				count++;
			}
			cout << 'R' << '\n';
			vector<ll>().swap(result);
		}
	}
	return 0;
}