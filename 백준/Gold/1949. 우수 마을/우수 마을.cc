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
    vector<ll>v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<vector<ll>>graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<vector<ll>>dp(n + 1, vector<ll>(2, -1));
    function<ll(ll, ll, ll)> dfs = [&](ll a, ll b, ll c) -> ll {
        if (dp[b][c] != -1) {
            return dp[b][c];
        }
        ll weight = 0;
        for (auto& i : graph[b]) {
            if (i != a) {
                if (!c) {
                    weight += max(dfs(b, i, 1) + v[i], dfs(b, i, 0));
                }
                else {
                    weight += dfs(b, i, 0);
                }
            }
        }
        return dp[b][c] = weight;
        };
    cout << max(dfs(0, 1, 0), dfs(0, 1, 1) + v[1]);
    return 0; 
}