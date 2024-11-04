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
	cin >> n >> m;
	vector<ll>v;
	for (int i = 0; i < m; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	ll result = 0;
	for (auto& i : v) {
		if (n < 200) {
			n += i;
			result++;
		}
	}
	cout << result;
	return 0;
}