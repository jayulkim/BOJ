#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v;
	for (int i = n; i >= 1; i--) {
		v.push_back(i);
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
	return 0;
}