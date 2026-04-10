#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	map<ll, pll>Map;
	for (int i = 0; i < n; i++) {
		ll a = 0;
		cin >> a;
		if (Map.find(m * a) == Map.end()) {
			Map[m * a] = { 1, 0 };
		}
		else {
			Map[m * a].first++;
		}
		if (Map.find((200 - m) * a) == Map.end()) {
			Map[(200 - m) * a] = { 0, 1 };
		}
		else {
			Map[(200 - m) * a].second++;
		}
	}
	ll temp = 0;
	for (auto& [a, b] : Map) {
		temp += b.first;
		if (temp >= k) {
			if (a % 100) {
				ll down = gcd(a, 100);
				cout << a / down << '/' << 100 / down;
			}
			else {
				cout << a / 100;
			}
			return 0;
		}
		temp -= b.second;
	}
	cout << -1;
	return 0;
}