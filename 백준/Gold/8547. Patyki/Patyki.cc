#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
map<ll, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		Map[num]++;
	}
	while (1) {
		bool Find = false;
		for (auto& i : Map) {
			if (i.second >= 2) {
				Find = true;
				Map[i.first] -= 2;
				Map[i.first * 2]++;
			}
		}
		if (!Find) {
			break;
		}
	}
	ll result = 0;
	for (auto& i : Map) {
		if (i.second > 0) {
			result++;
		}
	}
	cout << result;
	return 0;
}