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
    vector<ll>v;
    vector<ll>vv;
    for (int i = 0; i < n; i++) {
        cin >> k;
        v.push_back(k);
    }
    for (int i = 0; i < m; i++) {
        cin >> k;
        vv.push_back(k);
    }
    vector<vector<ll>>dp(n + 1, vector<ll>(m + 1, -1));
    function<ll(ll, ll)> dfs = [&](ll a, ll b) -> ll {
        if (a == n) {
            return 0;
        }
        if (n - a > m - b || b >= m) {
            return 1e9;
        }
        if (dp[a][b] != -1) {
            return dp[a][b];
        }
        return dp[a][b] = min(dfs(a + 1, b + 1) + v[a] * vv[b], dfs(a, b + 1));
        };
    cout << dfs(0, 0);
    return 0; 
}