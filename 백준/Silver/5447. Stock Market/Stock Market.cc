#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n;
        vector<ll>v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        vector<ll>dp(n + 1);
        vector<ll>idx(n + 1, 1);
        ll Max = LLONG_MIN;
        for (int i = 1; i <= n; i++) {
            if (v[i] > dp[i - 1] + v[i]) {
                dp[i] = v[i];
                idx[i] = i;
            }
            else {
                dp[i] = dp[i - 1] + v[i];
                idx[i] = idx[i - 1];
            }
            Max = max(Max, dp[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (dp[i] == Max) {
                cout << idx[i] << ' ' << i << '\n';
                break;
            }
        }
    }
    return 0;
}