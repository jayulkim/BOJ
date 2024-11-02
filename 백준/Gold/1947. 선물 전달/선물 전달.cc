#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0;
ll dp[1000001];
int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
    dp[2] = 1;
    cin >> n;
    for (ll j = 3; j <= n; j++) {
        dp[j] = ((j - 1) * (dp[j - 1] + dp[j - 2])) % 1000000000;
    }
    cout << dp[n];
	return 0;
}