#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll, ll>>v;
ll RSS(ll a, ll b) {
	ll result = 0;
	for (auto& i : v) {
		result += ((i.second - (a * i.first + b)) * (i.second - (a * i.first + b)));
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		ll x = 0, y = 0;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	ll Min = 9876543210000;
	ll resulta = 0, resultb = 0;
	for (ll i = 1; i <= 100; i++) {
		for (ll j = 1; j <= 100; j++) {
			if (Min > RSS(i, j)) {
				resulta = i;
				resultb = j;
				Min = RSS(i, j);
			}
		}
	}
	cout << resulta << ' ' << resultb;
	return 0;
}