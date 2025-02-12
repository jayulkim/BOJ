#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
vector<vector<vector<ll>>>dp(201, vector<vector<ll>>(201, vector<ll>(3, -1)));
vector<vector<ll>>v(201, vector<ll>(2, -1));
ll dfs(ll a, ll b, ll c) {
    if (a == n) {
        if (b < m) {
            return -1e9;
        }
        return 0;
    }
    if (dp[a][b][c] != -1) {
        return dp[a][b][c];
    }
    ll weight = 0;
    if (c == 0) {
        weight += max({ dfs(a + 1, b, 0) + v[a][0] + v[a][1], dfs(a + 1, b + 1, 1) + v[a][1], dfs(a + 1, b + 1, 2) + v[a][0] });
    }
    if (c == 1) {
        weight += max(dfs(a + 1, b, 0) + v[a][0] + v[a][1], dfs(a + 1, b + 1, 1) + v[a][1]);
    }
    if (c == 2) {
        weight += max(dfs(a + 1, b, 0) + v[a][0] + v[a][1], dfs(a + 1, b + 1, 2) + v[a][0]);
    }
    return dp[a][b][c] = weight;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    ll a = 0, b = 0;
    cin >> a >> b;
    cout << max({ dfs(0, 0, 0), dfs(0, 0, 1), dfs(0, 0, 2) });
    return 0;
}