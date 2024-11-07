#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
bool compare(const pll& a, const pll& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	ll temp = 1;
	cin >> num;
	while (num--) {
		ll n = 0;
		cin >> n;
		map<ll, vector<pll>>Map;
		for (int i = 0; i < n; i++) {
			ll a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			Map[a].push_back({ b, c });
		}
		ll result = 0;
		for (auto& i : Map) {
			sort(i.second.begin(), i.second.end(), compare);
		}
		for (auto& i : Map) {
			ll count = 1;
			ll end = i.second[0].second;
			for (int j = 1; j < i.second.size(); j++) {
				if (i.second[j].first >= end) {
					count++;
					end = i.second[j].second;
				}
			}
			result += count;
		}
		cout << "Scenario #" << temp << ":" << '\n';
		cout << result << '\n';
		cout << '\n';
		temp++;
	}
	return 0;
}