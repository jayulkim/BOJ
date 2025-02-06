#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
string a = "", b = "";
vector<vector<ll>>dp(3001, vector<ll>(3001, -1));
ll dfs(ll x, ll y) {
    if (x == a.length() && y == b.length()) {
        return 0;
    }
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    ll weight = -1e8;
    if (x < a.length()) {
        weight = max(weight, dfs(x + 1, y) + m);
    }
    if (y < b.length()) {
        weight = max(weight, dfs(x, y + 1) + m);
    }
    if (x < a.length() && y < b.length()) {
        if (a[x] == b[y]) {
            weight = max(weight, dfs(x + 1, y + 1) + n);
        }
        else {
            weight = max(weight, dfs(x + 1, y + 1) + k);
        }
    }
    return dp[x][y] = weight;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    cin >> a >> b;
    cout << dfs(0, 0);
    return 0;
}