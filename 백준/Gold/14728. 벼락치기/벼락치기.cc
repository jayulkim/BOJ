#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll dp[101][10001];
int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m;
    vector<pll>v(101);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j - v[i].first >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][m];
	return 0;
}