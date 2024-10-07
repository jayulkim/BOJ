#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
ll n = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll num = 0;
		cin >> num;
	}
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<ll>());
	ll temp = v[0];
	cout << temp << '\n';
	for (int i = 1; i < n; i++) {
		temp += v[i];
		cout << temp << '\n';
	}
	return 0;
}