#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
map<ll, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	ll count = 0;
	for (int i = 0; i < n; i++) {
		if (!Map[v[i]]) {
			Map[v[i] - 1]++;
			count++;
		}
		else {
			Map[v[i]]--;
			Map[v[i] - 1]++;
		}
	}
	cout << count;
	return 0;
}