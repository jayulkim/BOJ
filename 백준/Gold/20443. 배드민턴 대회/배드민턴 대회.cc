#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll n = 0;
ll dp[101];
ll addmod(ll x, ll y) {
    if (x >= mod - y) {
        return x - (mod - y);
    }
    return x + y;
}
ll mulmod(ll x, ll y) {
    ll result = 0;
    while (y > 0) {
        if (y % 2) {
            result = addmod(result, x);
        }
        x = addmod(x, x);
        y /= 2;
    }
    return result;
}
ll powmod(ll x, ll y) {
    ll result = 1;
    while (y > 0) {
        if (y % 2) {
            result = mulmod(result, x);
        }
        x = mulmod(x, x);
        y /= 2;
    }
    return result;
}
ll comb(ll n, ll k) {
    ll up = 1;
    for (ll i = 2; i <= n; i++) {
        up = mulmod(up, i);
    }
    ll down = 1;
    for (ll i = 2; i <= k; i++) {
        down = mulmod(down, i);
    }
    for (ll i = 2; i <= n - k; i++) {
        down = mulmod(down, i);
    }
    return mulmod(up, powmod(down, mod - 2));
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[2] = 1;
    for (ll j = 3; j <= 100; j++) {
        dp[j] = ((j - 1) * (dp[j - 1] + dp[j - 2])) % mod;
    }
    cin >> n;
    if (n % 4 == 0) {
        cout << dp[n];
    }
    else {
        ll temp = n;
        n -= (n % 4);
        cout << mulmod(comb(temp, temp % 4), dp[n]);
    }
    return 0;
}