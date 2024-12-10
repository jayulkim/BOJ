#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<pll>dp(300001, { -1, -1 });
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		ll num = 0;
		cin >> num;
		if (dp[num].first != -1) {
			cout << dp[num].first << ' ' << dp[num].second << '\n';
		}
		else {
			if (num > v.back()) {
				cout << v[0] << ' ' << v.back() << '\n';
				dp[num].first = v[0];
				dp[num].second = v.back();
			}
			else {
				ll temp = 0;
				ll Min = num;
				ll Max = 0;
				ll idx = 0;
				while (temp <= v.back()) {
					temp += num;
					auto it = lower_bound(v.begin(), v.end(), temp);
					Min = min(Min, v[idx] % num);
					idx = it - v.begin();
					if (it != v.begin()) {
						it--;
					}
					Max = max(Max, *it % num);
				}
				if (!v[0]) {
					Min = 0;
				}
				dp[num].first = Min;
				dp[num].second = Max;
				cout << Min << ' ' << Max << '\n';
			}
		}
	}
	return 0;
}