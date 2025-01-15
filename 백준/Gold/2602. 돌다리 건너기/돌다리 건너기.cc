#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
string a = "", b = "", c = "";
vector<vector<vector<ll>>>dp(101, vector<vector<ll>>(3, vector<ll>(101, -1)));
ll dfs(ll n, ll m, ll k) {
    if (n == a.length()) {
        return 1;
    }
    if (dp[n][m][k] != -1) {
        return dp[n][m][k];
    }
    ll weight = 0;
    if (m == 1) {
        for (int i = k; i < c.length(); i++) {
            if (c[i] == a[n]) {
                weight += dfs(n + 1, 2, i + 1);
            }
        }
    }
    else if (m == 2) {
        for (int i = k; i < b.length(); i++) {
            if (b[i] == a[n]) {
                weight += dfs(n + 1, 1, i + 1);
            }
        }
    }
    return dp[n][m][k] = weight;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c;
    cout << dfs(0, 1, 0) + dfs(0, 2, 0);
    return 0;
}