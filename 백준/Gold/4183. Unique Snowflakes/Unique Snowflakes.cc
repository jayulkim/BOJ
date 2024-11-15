#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		ll n = 0;
		cin >> n;
		vector<ll>v;
		for (int i = 0; i < n; i++) {
			ll a = 0;
			cin >> a;
			v.push_back(a);
		}
		map<ll, ll>Map;
		ll start = 0, end = 0;
		ll Max = 0;
		while (end < n) {
			Map[v[end]]++;
			if (Map[v[end]] <= 1) {
				Max = max(Max, (end - start + 1));
				end++;
			}
			else {
				Map[v[start]]--;
				Map[v[end]]--;
				start++;
			}
		}
		cout << Max << '\n';
	}
	return 0;
}