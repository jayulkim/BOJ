#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<vector<ll>>dp(100001, vector<ll>(3, -1));
vector<ll>v;
ll dfs(ll temp, ll count) {
	if (temp >= n) {
		return 0;
	}
	if (count >= 2) {
		return -1e12;
	}
	if (dp[temp][count] != -1) {
		return dp[temp][count];
	}
	ll weight = 0;
	if (temp + 1 < n) {
		weight = max({ weight, dfs(temp + 1, count + 1) + v[temp + 1] / 2, dfs(temp + 1, count) });
	}
	if (temp + 2 < n) {
		weight = max({ weight, dfs(temp + 2, 0) + v[temp + 2] });
	}
	return dp[temp][count] = weight;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	ll Max = 0;
	for (int i = 0; i < n; i++) {
		Max = max(Max, dfs(i, 0) + v[i]);
	}
	cout << Max;
	return 0;
}