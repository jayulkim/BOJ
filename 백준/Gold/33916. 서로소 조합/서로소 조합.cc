#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<ll>>dp(5001, vector<ll>(5001, 0));
	for (int i = 2; i <= 5000; i++) {
		dp[i] = dp[i - 1];
		ll temp = i;
		for (int j = 2; j <= temp && temp; j++) {
			while (temp % j == 0) {
				dp[i][j]++;
				temp /= j;
			}
		}
	}
	ll num = 0;
	cin >> num;
	while (num--) {
		ll a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		ll result = 1;
		for (int i = 2; i <= max(a, c); i++) {
			if ((dp[a][i] - dp[b][i] - dp[(a - b)][i] > 0) && (dp[c][i] - dp[d][i] - dp[(c - d)][i] > 0)) {
				result = 0;
				break;
			}
		}
		cout << result << '\n';
	}
	return 0;
}