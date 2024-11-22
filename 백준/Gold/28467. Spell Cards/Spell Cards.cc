#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<vector<ll>>dp(401, vector<ll>(401, -1));
vector<vector<ll>>Maxdp(401, vector<ll>(401, -1));
vector<ll>v;
ll Maxdfs(ll start, ll end) {
	if (start == end) {
		return Maxdp[start][end] = v[start];
	}
	if (Maxdp[start][end] != -1) {
		return Maxdp[start][end];
	}
	ll Max = 0;
	for (int i = start; i < end; i++) {
		Max = max({ Max, Maxdfs(start, i), Maxdfs(i + 1, end) });
	}
	return Maxdp[start][end] = Max;
}
ll dfs(ll start, ll end) {
	if (start == end) {
		return 0;
	}
	if (dp[start][end] != -1) {
		return dp[start][end];
	}
	ll result = LLONG_MAX;
	for (int i = start; i < end; i++) {
		result = min(result, dfs(start, i) + dfs(i + 1, end) + Maxdp[start][i] + Maxdp[i + 1][end]);
	}
	return dp[start][end] = result;
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
	Maxdfs(0, n - 1);
	cout << dfs(0, n - 1);
	return 0;
}