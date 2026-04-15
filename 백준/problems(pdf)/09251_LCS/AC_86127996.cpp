#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
string a = "", b = "";
vector<vector<ll>>dp(1001, vector<ll>(1001, -1));
ll dfs(ll aidx, ll bidx) {
	if (aidx == a.length() || bidx == b.length()) {
		return 0;
	}
	if (dp[aidx][bidx] != -1) {
		return dp[aidx][bidx];
	}
	ll weight = 0;
	if (a[aidx] == b[bidx]) {
		weight = max(weight, dfs(aidx + 1, bidx + 1) + 1);
	}
	else {
		weight = max({ weight, dfs(aidx + 1, bidx), dfs(aidx, bidx + 1) });
	}
	return dp[aidx][bidx] = weight;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	cout << dfs(0, 0);
	return 0;
}