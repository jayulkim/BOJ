#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
bitset<501> dp[1001][501];
ll v[1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= 2 * n - 1; i++) {
		cin >> v[i];
	}
	dp[0][0][0] = 1;
	for (int i = 1; i <= 2 * n - 1; i++) {
		for (int j = 0; j <= n; j++) {
			if (j > 0) {
				dp[i][j] |= dp[i - 1][j - 1] << v[i];
				dp[i][j] |= dp[i - 1][j - 1] >> (n - v[i]);
			}
			dp[i][j] |= dp[i - 1][j];
		}
	}
	ll temp = n;
	ll mod = 0;
	vector<ll>result;
	for (int i = 2 * n - 1; i >= 1 && temp; i--) {
		if (dp[i][temp][mod] && !dp[i - 1][temp][mod]) {
			result.push_back(v[i]);
			mod = (mod - v[i] + n) % n;
			temp--;
		}
	}
	if (!result.size()) {
		cout << -1;
		return 0;
	}
	for (auto& i : result) {
		cout << i << ' ';
	}
	return 0;
}