#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef tuple<ll, ll, ll, ll, ll> lllll;
typedef tuple<ll, ll, vector<ll>> llv;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<ll>>dp(n + 1, vector<ll>(m + 1, -1));
    string a = "", b = "";
    cin >> a >> b;
    function<ll(ll, ll)> dfs = [&](ll x, ll y) -> ll {
        if (y == m) {
            return 0;
        }
        if (x < 0 || x >= n) {
            return -1e9;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        ll weight = 0;
        if (a[x] == b[y]) {
            weight = max(weight, dfs(x - 1, y + 1) + 1);
            weight = max(weight, dfs(x + 1, y + 1) + 1);
        }
        else {
            weight = max(weight, dfs(x - 1, y + 1));
            weight = max(weight, dfs(x + 1, y + 1));
        }
        return dp[x][y] = weight;
        };
    ll Max = 0;
    for (int i = 0; i < n; i++) {
        Max = max(Max, dfs(i, 0));
    }
    cout << Max;
    return 0;
 }