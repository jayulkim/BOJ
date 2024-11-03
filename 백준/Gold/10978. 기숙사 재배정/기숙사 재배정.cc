#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0;
ll dp[21];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[2] = 1;
    for (ll j = 3; j <= 20; j++) {
        dp[j] = ((j - 1) * (dp[j - 1] + dp[j - 2]));
    }
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}