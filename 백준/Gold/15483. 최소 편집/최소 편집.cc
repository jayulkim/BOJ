//폰 코딩
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
    string a = "", b = "";
    cin >> a >> b;
    vector<vector<ll>>dp(1001, vector<ll>(1001, 0));
    for (int i = 1; i <= a.length(); i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= b.length(); i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= a.length(); i++) {
         for (int j = 1; j <= b.length(); j++) {
             if (a[i - 1] == b[j - 1]) {
                 dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1]});
             }
             else {
                 dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
             }
         }
    }
    cout << dp[a.length()][b.length()];
    return 0;
}