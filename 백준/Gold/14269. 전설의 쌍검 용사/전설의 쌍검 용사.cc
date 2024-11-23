#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
map<ll, ll>Map;
bool compare(const pll& a, const pll& b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<tp>v;
	ll result = 0;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		ll a = 0, b = 0;
		cin >> num >> a >> b;
		Map[num]++;
		v.push_back({ num, a, b });
	}
	result += Map.size();
	vector<pll>vv;
	for (auto& i : v) {
		auto it = Map.lower_bound(get<1>(i));
		if (it == Map.end() || it->first > get<2>(i)) {
			pll temp = { get<1>(i), get<2>(i) };
			vv.push_back(temp);
		}
		else if (it->first == get<0>(i) && it->second == 1 && (next(it) == Map.end() || next(it)->first > get<2>(i))) {
			result++;
		}
	}
	sort(vv.begin(), vv.end(), compare);
	ll left = 0, right = 0;
	for (auto& i : vv) {
		left = max(left, i.first);
		right = min(right, i.second);
		if (left > right) {
			result++;
			left = i.first;
			right = i.second;
		}
	}
	cout << result;
	return 0;
}