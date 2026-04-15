#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	string str = "";
	cin >> str;
	vector<ll>v(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	string temp = "UOSPC";
	vector<vector<ll>>dp(n + 1, vector<ll>(6, -1));
	function<ll(ll, ll)> dfs = [&](ll a, ll b) -> ll {
		if (b == 5) {
			return 0;
		}
		if (a == n) {
			if (b == 5) {
				return 0;
			}
			return 1e18;
		}
		if (dp[a][b] != -1) {
			return dp[a][b];
		}
		ll weight = 1e18;
		if (str[a] == temp[b]) {
			weight = min(weight, dfs(a + 1, b + 1) + v[a]);
		}
		weight = min(weight, dfs(a + 1, b));
		return dp[a][b] = weight;
		};
	ll result = dfs(0, 0);
	if (result == 1e18) {
		cout << -1;
	}
	else {
		cout << result;
	}
	return 0;
}