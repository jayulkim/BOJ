#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
ll v[101];
vector<vector<vector<ll>>>dp(101, vector<vector<ll>>(101, vector<ll>(101, -1)));
ll dfs(ll a, ll b, ll c) {
    if (a > n) {
        return 1;
    }
    if (dp[a][b][c] != -1) {
        return dp[a][b][c] % 10000;
    }
    ll weight = 0;
    if (v[a]) {
        if (v[a] == b && b == c) {
            return 0;
        }
        weight += dfs(a + 1, c, v[a]);
    }
    else {
        for (int i = 1; i <= 3; i++) {
            if (!(b == c && c == i)) {
                weight += dfs(a + 1, c, i) % 10000;
                weight %= 10000;
            }
        }
    }
    return dp[a][b][c] = weight % 10000;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v[a] = b;
    }
    ll result = 0;
    ll a = 0, b = 0;
    if (v[1]) {
        a = v[1];
    }
    if (v[2]) {
        b = v[2];
    }
    if (a && b) {
        cout << dfs(3, a, b);
    }
    else if (a && !b) {
        for (int i = 1; i <= 3; i++) {
            result += dfs(3, v[1], i) % 10000;
            result %= 10000;
        }
        cout << result % 10000;
    }
    else if (!a && b) {
        for (int i = 1; i <= 3; i++) {
            result += dfs(3, i, v[2]) % 10000;
            result %= 10000;
        }
        cout << result % 10000;
    }
    else {
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                result += dfs(3, i, j) % 10000;
                result %= 10000;
            }
        }
        cout << result % 10000;
    }
    return 0;
}