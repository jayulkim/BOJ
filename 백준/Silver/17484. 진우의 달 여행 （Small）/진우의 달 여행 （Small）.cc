#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<vector<vector<ll>>>dp(7, vector<vector<ll>>(7, vector<ll>(3, -1)));
ll Map[7][7];
ll dfs(ll a, ll b, ll c) {
	if (b < 0 || b >= m) {
		return 1e9;
	}
	if (a >= n) {
		return 0;
	}
	if (dp[a][b][c] != -1) {
		return dp[a][b][c];
	}
	ll weight = LLONG_MAX;
	if (!c) {
		weight = min({ weight, dfs(a + 1, b - 1, 1) + Map[a][b], dfs(a + 1, b + 1, 2) + Map[a][b] });
	}
	else if (c == 1) {
		weight = min({ weight, dfs(a + 1, b, 0) + Map[a][b], dfs(a + 1, b + 1, 2) + Map[a][b] });
	}
	else if (c == 2) {
		weight = min({ weight, dfs(a + 1, b, 0) + Map[a][b], dfs(a + 1, b - 1, 1) + Map[a][b] });
	}
	return dp[a][b][c] = weight;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	ll Min = LLONG_MAX;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 3; j++) {
			Min = min(Min, dfs(0, i, j));
		}
	}
	cout << Min;
	return 0;
}