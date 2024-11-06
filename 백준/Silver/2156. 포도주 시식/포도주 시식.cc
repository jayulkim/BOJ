#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<ll>v;
vector<ll>dp(10001, -1);
ll n = 0;
ll dfs(ll idx) {
	if (idx >= n) {
		return 0;
	}
	if (dp[idx] != -1) {
		return dp[idx];
	}
	ll weight = 0;
	weight = max(weight, dfs(idx + 1));
	weight = max(weight, dfs(idx + 2) + v[idx]);
	if (idx + 1 < n) {
		weight = max(weight, dfs(idx + 3) + v[idx] + v[idx + 1]);
	}
	return dp[idx] = weight;
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
	cout << dfs(0);
	return 0;
}