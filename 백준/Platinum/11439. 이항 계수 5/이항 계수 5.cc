#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll up[4000001];
ll down[4000001];
bool ary[4000001];
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
	for (int i = 2; i * i <= 4000000; i++) {
		if (!ary[i]) {
			for (int j = i * i; j <= 4000000; j += i) {
				ary[j] = true;
			}
		}
	}
	vector<ll>prime;
	for (ll i = 2; i <= 4000000; i++) {
		if (!ary[i]) {
			prime.push_back(i);
		}
	}
	cin >> n >> m >> k;
	int idx = 0;
	while (idx < prime.size() && prime[idx] <= n) {
		ll temp = prime[idx];
		for (int i = 0; i < log(n) / log(prime[idx]); i++) {
			up[prime[idx]] += (n / temp);
			temp *= prime[idx];
		}
		idx++;
	}
	idx = 0;
	while (idx < prime.size() && prime[idx] <= m) {
		ll temp = prime[idx];
		for (int i = 0; i < log(m) / log(prime[idx]); i++) {
			down[prime[idx]] += (m / temp);
			temp *= prime[idx];
		}
		idx++;
	}
	idx = 0;
	while (idx < prime.size() && prime[idx] <= n - m) {
		ll temp = prime[idx];
		for (int i = 0; i < log(n - m) / log(prime[idx]); i++) {
			down[prime[idx]] += ((n - m) / temp);
			temp *= prime[idx];
		}
		idx++;
	}
	for (int i = 2; i <= 4000000; i++) {
		up[i] -= down[i];
	}
	ll result = 1;
	for (ll i = 2; i <= 4000000; i++) {
		result *= powmod(i, up[i], k);
		result %= k;
	}
	cout << result;
	return 0;
}