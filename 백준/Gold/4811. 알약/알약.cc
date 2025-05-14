//폰 코딩
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
    while (1) {
        cin >> n;
        if (!n) {
            break;
        }
        vector<vector<ll>>dp(n + 1, vector<ll>(n + 1, -1));
        function<ll(ll, ll)> dfs = [&](ll a, ll b) -> ll {
            if (!a && !b) {
                return dp[a][b] = 1;
            }
            if (dp[a][b] != -1) {
                return dp[a][b];
            }
            ll weight = 0;
            if (a) {
                weight += dfs(a - 1, b + 1) ;
            }
            if (b) {
                 weight += dfs(a, b - 1);
            }
            return dp[a][b] = weight;
            };
        cout << dfs(n, 0) << '\n';    
    }
    return 0;
}