#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<string>v;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str = "";
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end());
	ll count = 0;
	for (int i = 0; i < m; i++) {
		string str = "";
		cin >> str;
		auto it = lower_bound(v.begin(), v.end(), str);
		if (it != v.end()) {
			bool find = false;
			for (int j = 0; j < str.length(); j++) {
				if (v[it - v.begin()][j] != str[j]) {
					find = true;
					break;
				}
			}
			if (!find) {
				count++;
			}
		}
	}
	cout << count;
	return 0;
}