#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<vector<vector<ll>>>dp(11, vector<vector<ll>>(101, vector<ll>(101, -1)));
ll dfs(ll a, ll b, ll c) {
	if (b == c) {
		return 0;
	}
	if (!a) {
		return 1e18;
	}
	if (dp[a][b][c] != -1) {
		return dp[a][b][c];
	}
	ll weight = 1e18;
	for (int i = b + 1; i <= c; i++) {
		weight = min(weight, max(i + dfs(a - 1, b, i - 1), i + dfs(a, i, c)));
	}
	return dp[a][b][c] = weight;
}
int main(void) {
	ios::sync_with_stdio(false);
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n >> m;
		cout << dfs(n, 0, m) << '\n';
		vector<vector<vector<ll>>>(11, vector<vector<ll>>(101, vector<ll>(101, -1))).swap(dp);
	}
	return 0;
}