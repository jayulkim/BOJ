#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll> lll;
typedef tuple<pll, string, ll> pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		sum += num - 1;
	}
	if (sum < m) {
		cout << "OUT";
	}
	else {
		cout << "DIMI";
	}
	return 0;
}