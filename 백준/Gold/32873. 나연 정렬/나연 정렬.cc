#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[501];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		auto it = lower_bound(v.begin(), v.end(), num);
		if (it == v.end()) {
			v.push_back(num);
		}
		else {
			v[it - v.begin()] = num;
		}
	}
	cout << v.size();
	return 0;
}