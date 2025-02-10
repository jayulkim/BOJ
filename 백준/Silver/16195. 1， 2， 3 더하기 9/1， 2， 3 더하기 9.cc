#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
vector<vector<ll>>dp(1001, vector<ll>(1001, 0));
#define mod 1000000009
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;
    for (int i = 4; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 2][j - 1] % mod + dp[i - 3][j - 1] % mod) % mod;
        }
    }
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n >> m;
        ll result = 0;
        for (int i = 1; i <= m; i++) {
            result += dp[n][i] % mod;
            result %= mod;
        }
        cout << result << '\n';
    }
    return 0;
}