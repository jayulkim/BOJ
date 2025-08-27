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
    vector<vector<vector<ll>>>dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, -1)));
    vector<pll>v;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        v.push_back({ num, i });
    }
    function<ll(ll, ll, ll)> dfs = [&](ll a, ll b, ll c) -> ll {
        if (a >= n) {
            return 0;
        }
        if (v[c].first - v[b].first >= m) {
            return 0;
        }
        if (dp[a][b][c] != -1) {
            return dp[a][b][c];
        }
        ll weight = 1e9;
        if (a + 2 < n) {
            weight = min(weight, dfs(a + 2, min(v[b], v[a + 2]).second, max(v[c], v[a + 2]).second) + 1);
        }
        if (a + 1 < n) {
            weight = min(weight, dfs(a + 1, min(v[b], v[a + 1]).second, max(v[c], v[a + 1]).second) + 1);
        }
        return dp[a][b][c] = weight;
        };
    cout << min(dfs(0, 0, 0) + 1, n);
    return 0;
}