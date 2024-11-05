#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(50001);
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v[num]++;
	}
	ll Max = 0;
	for (int i = 1; i <= 50000; i++) {
		Max = max(Max, v[i]);
	}
	cout << Max;
	return 0;
}