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
    string str = "";
    cin >> str;
    map<char, ll>Map;
    Map['B'] = 0;
    Map['O'] = 1;
    Map['J'] = 2;
    vector<vector<ll>>dp(n + 1, vector<ll>(3, -1));
    function<ll(ll, ll)> dfs = [&](ll a, ll b) -> ll {
        if (a == n - 1) {
            return 0;
        }
        if (dp[a][b] != -1) {
            return dp[a][b];
        }
        ll weight = 1e18;
        for (int i = a + 1; i < n; i++) {
            if (Map[str[i]] == (b + 1) % 3) {
                weight = min(weight, dfs(i, (b + 1) % 3) + (i - a) * (i - a));
            }
        }
        return dp[a][b] = weight;
        };
    ll result = dfs(0, 0);
    if (result == 1e18) {
        cout << -1;
    }
    else {
        cout << result;
    }
    return 0; 
}