#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
ll need[33];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		for (int j = 0; j <= 32; j++) {
			if ((num >> j) & 1) {
				need[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		ll temp = 0;
		for (int j = 0; j <= 32; j++) {
			if (need[j]) {
				temp |= (1LL << j);
				need[j]--;
			}
		}
		cout << temp << ' ';
	}
	return 0;
}