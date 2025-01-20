#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
vector<vector<ll>>dp(5001, vector<ll>(5001, -1));
string a = "", b = "";
ll dfs(ll n, ll m) {
	if (m == b.length()) {
		return 0;
	}
	if (dp[n][m] != -1) {
		return dp[n][m];
	}
	ll weight = 0;
	if (n > 0) {
		weight = max(weight, dfs(n - 1, m + 1));
	}
	if (n < a.length() - 1) {
		weight = max(weight, dfs(n + 1, m + 1));
	}
	if (a[n] == b[m]) {
		weight++;
	}
	return dp[n][m] = weight;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> a >> b;
	if (m == 1) {
		for (int i = 0; i < n; i++) {
			if (a[i] == b[0]) {
				cout << 1;
				return 0;
			}
		}
		cout << 0;
		return 0;
	}
	ll Max = 0;
	for (int i = 0; i < n; i++) {
		Max = max(Max, dfs(i, 0));
	}
	cout << Max;
	return 0;
}