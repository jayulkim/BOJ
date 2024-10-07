#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll powmod(ll x, ll y, ll num) {
	ll result = 1;
	x %= num;
	while (y > 0) {
		if (y % 2 == 1) {
			result *= x;
			result %= num;
		}
		x *= x;
		x %= num;
		y /= 2;
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll result = 0;
	for (int i = 0; i < n - 1; i++) {
		result += (v[i + 1] - v[i]);
		result %= 1000000007;
	}
	vector<ll>sum(n);
	sum[0] = v[0];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + v[i];
	}
	for (int i = n - 2; i >= 1; i--) {
		result += ((sum[n - 1] - sum[i] - sum[n - 2 - i]) % 1000000007) * (powmod(2, i, 1000000007) % 1000000007);
		result %= 1000000007;
	}
	cout << result;
	return 0;
}