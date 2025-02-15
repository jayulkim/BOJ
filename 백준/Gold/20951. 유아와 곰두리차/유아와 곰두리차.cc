#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[100001];
vector<vector<ll>>dp(100001, vector<ll>(8, -1));
#define mod 1000000007
ll dfs(ll a, ll b) {
    if (b == 8) {
        return 1;
    }
    if (dp[a][b] != -1) {
        return dp[a][b] % mod;
    }
    ll weight = 0;
    for (auto& i : graph[a]) {
        weight += dfs(i, b + 1) % mod;
        weight %= mod;
    }
    return dp[a][b] = weight % mod;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        graph[0].push_back(i);
    }
    ll sum = 0;
    cout << dfs(0, 0) % mod;
    return 0;
}