#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Map[1001][1001];
ll dp[1001][1001];
int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m;
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= m; k++) {
            cin >> Map[j][k];
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= m; k++) {
            dp[j][k] = max({ dp[j][k - 1], dp[j - 1][k], dp[j - 1][k - 1] }) + Map[j][k];
        }
    }
    cout <<dp[n][m];
	return 0;
}