#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<ll>v;
vector<ll>dp(1001, -1);
ll n = 0;
ll dfs(ll idx) {
	if (idx == n) {
		return 0;
	}
	if (dp[idx] != -1) {
		return dp[idx];
	}
	ll weight = 1;
	for (int i = idx + 1; i < n; i++) {
		if (v[i] > v[idx]) {
			weight = max(weight, dfs(i) + 1);
		}
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
	ll Max = 0;
	for (int i = 0; i < n; i++) {
		Max = max(Max, dfs(i));
	}
	cout << Max;
	return 0;
}