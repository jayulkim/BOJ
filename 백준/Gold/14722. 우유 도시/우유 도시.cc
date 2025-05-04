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
    vector<vector<ll>>Map(n + 1, vector<ll>(n + 1));
    vector<vector<vector<ll>>>dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(5, -1)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> Map[i][j];
        }
    }
    function<ll(ll, ll, ll)> dfs = [&](ll y, ll x, ll temp) -> ll {
        if (y > n || x > n) {
            return 0;
        }
        if (dp[y][x][temp] != -1) {
            return dp[y][x][temp];
        }
        ll weight = 0;
        ll a = 0;
        if (Map[y][x] == temp) {
            a = max({a, dfs(y + 1, x, (temp + 1) % 3) + 1, dfs(y, x + 1, (temp + 1) % 3) + 1});
        }
        else {
            a = max({a, dfs(y + 1, x, temp), dfs(y, x + 1, temp)});
        }
        weight += a;
        return dp[y][x][temp] = weight;
        };
    cout << dfs(1, 1, 0);
    return 0;
}