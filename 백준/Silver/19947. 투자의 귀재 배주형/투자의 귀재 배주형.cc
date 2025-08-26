#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<ll>dp(m + 1, n);
    for (int i = 1; i <= m; i++) {
        ll weight = dp[i - 1] + dp[i - 1] / 20;
        if (i >= 3) {
            weight = max(weight, dp[i - 3] + dp[i - 3] / 5);
        }
        if (i >= 5) {
            weight = max(weight, dp[i - 5] + (dp[i - 5] * 7) / 20);
        }
        dp[i] = weight;
    }
    cout << dp[m];
    return 0;
}