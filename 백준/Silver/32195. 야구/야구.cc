#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll getdist(ll x, ll y) {
	return x * x + y * y;
}
map<ll, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll count = 0;
	ll n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		if (!(a == 0 && b == 0)) {
			if ((a <= 0 && b <= 0) || (a >= 0 && b <= 0) || (llabs(a) > llabs(b))) {
				count++;
			}
			else {
				Map[getdist(a, b)]++;
			}
		}
		else {
			Map[getdist(a, b)]++;
		}
	}
	vector<pll>v;
	for (auto& i : Map) {
		v.push_back({ i.first, i.second });
	}
	for (int i = 1; i < v.size(); i++) {
		v[i].second += v[i - 1].second;
	}
	ll m = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		ll num = 0;
		cin >> num;
		if (num * num == lower_bound(v.begin(), v.end(), make_pair(num * num, -LLONG_MAX))->first) {
			cout << count << ' ' << lower_bound(v.begin(), v.end(), make_pair(num * num, -LLONG_MAX))->second << ' ' << n - lower_bound(v.begin(), v.end(), make_pair(num * num, -LLONG_MAX))->second - count << '\n';
		}
		else {
			cout << count << ' ' << lower_bound(v.begin(), v.end(), make_pair(num * num, -LLONG_MAX))->second - 1 << ' ' << n - lower_bound(v.begin(), v.end(), make_pair(num * num, -LLONG_MAX))->second - count + 1 << '\n';
		}
	}
	return 0;
}