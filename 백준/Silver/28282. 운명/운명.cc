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
	cin >> n >> m;
	vector<ll>v;
	for (int i = 0; i < 2 * n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	map<ll, ll>Map;
	for (int i = n; i < 2 * n; i++) {
		Map[v[i]]++;
	}
	ll result = 0;
	for (int i = 0; i < n; i++) {
		result += (n - Map[v[i]]);
	}
	cout << result;
	return 0;
}