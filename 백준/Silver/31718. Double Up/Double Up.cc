#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin >> n;
	map<ll, ll>Map;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		while (num < 1e9) {
			Map[num]++;
			num *= 2;
		}
	}
	ll Max = 0;
	for (auto& i : Map) {
		Max = max(Max, i.second);
	}
	cout << Max;
	return 0;
}