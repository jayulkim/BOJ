#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
typedef pair<ll, string> pls;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<ll>dp(m + 1, -1);
    function<ll(ll)> dfs = [&](ll a) -> ll {
        if (dp[a] != -1) {
            return dp[a];
        }
        for (ll i = a + 1; i <= m; i++) {
            if (__gcd(i, a) == 1) {
                if (!dfs(i)) {
                    return dp[a] = 1;
                }
            }
        }
        return dp[a] = 0;
        };
    ll result = dfs(n);
    if (result) {
        cout << "khj20006";
    }
    else {
        cout << "putdata";
    }
    return 0;
}