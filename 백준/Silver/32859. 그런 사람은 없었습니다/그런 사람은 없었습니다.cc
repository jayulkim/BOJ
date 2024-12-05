#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
map<ll, ll>Map;
bool form[2001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> k;
	vector<ll>result;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		if (b == 1) {
			if (!form[a]) {
				Map[a]++;
			}
		}
		else {
			if (Map[a] - 1 >= k) {
				result.push_back(a);
				Map.erase(a);
			}
			else {
				Map.erase(a);
			}
			for (auto& j : Map) {
				j.second++;
			}
			form[a] = true;
		}
	}
	for (auto& i : Map) {
		if (i.second - 1 >= k) {
			result.push_back(i.first);
		}
	}
	if (!result.size()) {
		cout << -1;
		return 0;
	}
	sort(result.begin(), result.end());
	for (auto& i : result) {
		cout << i << '\n';
	}
	return 0;
}