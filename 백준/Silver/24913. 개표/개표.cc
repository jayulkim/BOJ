#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, char> llc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll dp[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll sum = 0;
	ll temp = 0;
	ll Max = 0;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 1) {
			if (c != n + 1) {
				sum += b;
				dp[c] += b;
				Max = max(Max, dp[c]);
			}
			else {
				temp += b;
			}
		}
		else {
			if (Max < temp + b && c <= ((temp + b - 1) * n - sum)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
	return 0;
}