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
    vector<vector<vector<ll>>>dp(101, vector<vector<ll>>(101, vector<ll>(2, -1)));
    function<ll(ll, ll, ll)> dfs = [&](ll a, ll b, ll c) -> ll {
        if (a < b || a < 1 || b < 0) {
            return 0;
        }
        if (a == 1 && !b) {
            return 1;
        }
        if (dp[a][b][c] != -1) {
            return dp[a][b][c];
        }
        ll weight = 0;
        if (!c) {
            weight += dfs(a - 1, b, 1);
            weight += dfs(a - 1, b, 0);
        }
        else {
            weight += dfs(a - 1, b - 1, 1);
            weight += dfs(a - 1, b, 0);
        }
        return dp[a][b][c] = weight;
        };
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n >> m;
        cout << dfs(n, m, 0) + dfs(n, m, 1) << '\n';
    }
    return 0;
}