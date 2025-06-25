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
    cin >> n;
    vector<ll>dp(41);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= 40; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << ' ' << n - 2;
    return 0;
}