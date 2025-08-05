#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll dp[10001][501][2];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<ll>v;
    for (int i = 0; i < n; i++) {
        ll a = 0;
        cin >> a;
        v.push_back(a);
        for (int j = 0; j <= m; j++) {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
    function<ll(ll, ll, ll)> dfs = [&](ll a, ll b, ll c) -> ll {
        if (a >= n) {
            if (b) {
                return -1e9;
            }
            return 0;
        }
        if (dp[a][b][c] != -1) {
            return dp[a][b][c];
        }
        ll weight = -1e9;
        if (b + 1 <= m && (!c || !b)) {
            weight = max(weight, dfs(a + 1, b + 1, 0) + v[a]);
        }
        weight = max(weight, dfs(a + 1, max((ll)0, b - 1), 1));
        return dp[a][b][c] = weight;
        };
    cout << dfs(0, 0, 1);
    return 0;
}