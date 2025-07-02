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
    cin >> n >> m >> k;
    vector<vector<ll>>v(n + 1, vector<ll>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<vector<vector<ll>>>>dp(n + 1, vector<vector<vector<ll>>>(m + 1, vector<vector<ll>>(2, vector<ll>(n + 1, -1))));
    function<ll(ll, ll, ll, ll)> dfs = [&](ll a, ll b, ll c, ll d) -> ll {
        if (a == n) {
            if (d < k) {
                return -1e18;
            }
            return 0;
        }
        if (dp[a][b][c][d] != -1) {
            return dp[a][b][c][d];
        }
        ll weight = -1e18;
        if (b + 1 <= m) {
            weight = max(weight, dfs(a + 1, b + 1, 0, d) + v[a][3]);
        }
        if (!c) {
            weight = max(weight, dfs(a + 1, b, 1, d) + v[a][2]);
        }
        weight = max(weight, dfs(a + 1, b, 0, d + 1) + max(v[a][0], v[a][1]));
        return dp[a][b][c][d] = weight;
        };
    cout << dfs(0, 0, 0, 0);
    return 0;
}