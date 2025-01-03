#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Map[101][101];
vector<vector<ll>>dp(101, vector<ll>(101, -1));
ll dfs(ll y, ll x) {
	if (y >= n || x >= n) {
		return 0;
	}
	if (y == n - 1 && x == n - 1) {
		return 1;
	}
	else if (!Map[y][x]) {
		return 0;
	}
	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	return dp[y][x] = dfs(y, x + Map[y][x]) + dfs(y + Map[y][x], x);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
		}
	}
	cout << dfs(0, 0);
	return 0;
}