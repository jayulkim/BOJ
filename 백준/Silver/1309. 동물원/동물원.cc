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
    vector<vector<ll>>dp(n + 1, vector<ll>(3, -1));
    function<ll(ll, ll)> dfs = [&](ll a, ll b) -> ll {
        if (a == n - 1) {
            return 1;
        }
        if (dp[a][b] != -1) {
            return dp[a][b];
        }
        if (b == 0) {
            return dp[a][b] = (dfs(a + 1, 0) + dfs(a + 1, 1) + dfs(a + 1, 2)) % 9901;
        }
        else if (b == 1) {
            return dp[a][b] = (dfs(a + 1, 0) + dfs(a + 1, 2)) % 9901;
        }
        else if (b == 2) {
            return dp[a][b] = (dfs(a + 1, 0) + dfs(a + 1, 1)) % 9901;
        }
        };
    cout << (dfs(0, 0) + dfs(0, 1) + dfs(0, 2)) % 9901;
    return 0;
}