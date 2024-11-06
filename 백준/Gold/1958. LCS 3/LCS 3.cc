#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
string a = "", b = "", c = "";
vector<vector<vector<ll>>>dp(101, vector<vector<ll>>(101, vector<ll>(101, -1)));
ll dfs(ll aidx, ll bidx, ll cidx) {
	if (aidx == a.length() || bidx == b.length() || cidx == c.length()) {
		return 0;
	}
	if (dp[aidx][bidx][cidx] != -1) {
		return dp[aidx][bidx][cidx];
	}
	ll weight = 0;
	if (a[aidx] == b[bidx] && b[bidx] == c[cidx]) {
		weight = max(weight, dfs(aidx + 1, bidx + 1, cidx + 1) + 1);
	}
	else {
		weight = max({ weight, dfs(aidx + 1, bidx, cidx), dfs(aidx, bidx + 1, cidx), dfs(aidx, bidx, cidx + 1) });
	}
	return dp[aidx][bidx][cidx] = weight;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> c;
	cout << dfs(0, 0, 0);
	return 0;
}