#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll addmod(ll x, ll y, ll num) {
    if (x >= num - y) {
        return x - (num - y);
    }
    return x + y;
}
int dp[100001][2];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[1][0] = 1;
    dp[1][1] = 0;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 2;
    dp[3][1] = 2;
    for (int i = 4; i <= 100000; i++) {
        dp[i][0] = addmod(addmod(dp[i - 1][1], dp[i - 2][1], 1000000009), dp[i - 3][1], 1000000009);
        dp[i][1] = addmod(addmod(dp[i - 1][0], dp[i - 2][0], 1000000009), dp[i - 3][0], 1000000009);
    }
    int n = 0;
    cin >> n;
    while (n--) {
        int num = 0;
        cin >> num;
        cout << dp[num][0] << ' ' << dp[num][1] << '\n';
    }
    return 0;
}
