#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>yaksoo[1000001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 1000000; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (j * j == i) {
				if ((i | j) == i) {
					yaksoo[i].push_back(j);
				}
			}
			else {
				if (i % j == 0 && i != j) {
					if ((i | j) == i) {
						yaksoo[i].push_back(j);
					}
					if ((i | (i / j)) == i && i != (i / j)) {
						yaksoo[i].push_back(i / j);
					}
				}
			}
		}
	}
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n;
		vector<ll>v(1000001, 0);
		vector<ll>vv;
		for (int i = 0; i < n; i++) {
			ll num = 0;
			cin >> num;
			v[num]++;
			vv.push_back(num);
		}
		ll result = 0;
		for (int i = 0; i < n; i++) {
			for (auto& j : yaksoo[vv[i]]) {
				result += (v[vv[i] - j]);
			}
		}
		cout << result << '\n';
	}
	return 0;
}