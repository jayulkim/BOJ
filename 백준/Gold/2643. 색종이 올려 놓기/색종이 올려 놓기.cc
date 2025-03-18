#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<pll>v;
vector<ll>dp(101, -1);
ll dfs(ll a) {
	if (a >= n) {
		return 0;
	}
	if (dp[a] != -1) {
		return dp[a];
	}
	ll weight = 1;
	for (int i = a + 1; i < n; i++) {
		if (v[i].first <= v[a].first && v[i].second <= v[a].second) {
			weight = max({ weight, dfs(i) + 1 });
		}
	}
	return dp[a] = weight;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		if (b < a) {
			swap(a, b);
		}
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end(), greater<pll>());
	ll Max = 0;
	for (int i = 0; i < n; i++) {
		Max = max(Max, dfs(i));
	}
	cout << Max;
	return 0;
}