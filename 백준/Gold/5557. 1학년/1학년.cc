#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<ll>v;
vector<vector<ll>>dp(101, vector<ll>(21, -1));
ll n = 0;
ll dfs(ll idx, ll sum) {
	if (idx == n - 1) {
		if (v.back() == sum) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (sum < 0 || sum > 20) {
		return 0;
	}
	if (dp[idx][sum] != -1) {
		return dp[idx][sum];
	}
	ll temp = 0;
	temp += dfs(idx + 1, sum - v[idx]);
	temp += dfs(idx + 1, sum + v[idx]);
	return dp[idx][sum] = temp;
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
	cout << dfs(1, v[0]);
	return 0;
}