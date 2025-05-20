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
    cin >> n;
    vector<ll>v;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
    }
    vector<ll>dp(n + 1, -1);
    function<ll(ll)> dfs = [&](ll a) -> ll {
        if (a >= n) {
            return 0;
        }
        if (dp[a] != -1) {
            return dp[a];
        }
        ll weight = LLONG_MAX;
        for (int i = 1; i <= v[a]; i++) {    
            weight = min(weight, dfs(a + i) + 1);
        }
        return dp[a] = weight;
        };
    cout << dfs(0);    
    return 0;
}