#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	if (k == 1) {
		cout << 1;
		return 0;
	}
	if (n % 2 == 0 && m % 2 == 0) {
		cout << 1;
		return 0;
	}
	if (n % 2 == 1 && m % 2 == 1) {
		cout << 0;
		return 0;
	}
	if (n % 2 != m % 2) {
		cout << 1;
		return 0;
	}
	return 0;
}