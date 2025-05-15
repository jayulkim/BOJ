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
    vector<bool>visited(200001, false);
    for (int i = 2; i * i <= 200000; i++) {
        if (!visited[i]) {
            for (int j = i * i; j <= 200000; j += i) {
                visited[j] = true;
            }
        }
    }
    visited[1] = true;
    cin >> n >> m >> k;
    vector<vector<ll>>Map(2, vector<ll>(n + 1));
    vector<ll>dp(n + 1, -1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Map[i][j];
        }
    }
    function<ll(ll)> dfs = [&](ll a) -> ll {
        if (a >= n) {
            return 0;
        }
        if (dp[a] != -1) {
            return dp[a];
        }
        ll weight = 0;
        if (a + 1 < n) {
            ll temp = 0;
            if (!visited[Map[0][a] + Map[0][a + 1]]) {
                temp += m;
            }
            else {
                temp += k;
            }
            if (!visited[Map[1][a] + Map[1][a + 1]]) {
                temp += m;
            }
            else {
                temp += k;
            }
            weight = max(weight, dfs(a + 2) + temp);
        }
        if (!visited[Map[0][a] + Map[1][a]]) {
            weight = max(weight, dfs(a + 1) + m);
        }
        else {
            weight = max(weight, dfs(a + 1) + k);
        }
        return dp[a] = weight;
        };
    cout << dfs(0);
    return 0;
}