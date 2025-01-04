#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> n;
		if (!n) {
			break;
		}
		vector<ll>v;
		for (int i = 0; i < n; i++) {
			ll num = 0;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		if (v[0] != 0) {
			cout << "IMPOSSIBLE" << '\n';
		}
		else {
			bool find = false;
			for (int i = 1; i < n; i++) {
				if (v[i] - v[i - 1] > 200) {
					cout << "IMPOSSIBLE" << '\n';
					find = true;
					break;
				}
			}
			if (!find) {
				if ((1422 - v.back()) * 2 > 200) {
					cout << "IMPOSSIBLE" << '\n';
				}
				else {
					cout << "POSSIBLE" << '\n';
				}	
			}
		}
	}
	return 0;
}