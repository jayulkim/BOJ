#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<char, ll, ll> cll;
typedef tuple<ll, ll, ll, ll> llll;
typedef tuple<ll, ll, ll, ll, ll> lllll;
typedef tuple<ll, ll, vector<ll>> llv;
typedef pair<ll, ll> pll;
typedef pair<vector<ll>, ll> pvl;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<pll>v;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    ll start = 0, end = m, mid = 0;
    ll Min = LLONG_MAX;
    while (start <= end) {
        mid = (start + end) / 2;
        vector<vector<ll>>dp(n + 1, vector<ll>(m - mid + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m - mid; j++) {
                if (j >= max((ll)0, v[i - 1].first - mid)) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - max((ll)0, v[i - 1].first - mid)] + v[i - 1].second);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][m - mid] >= k) {
            end = mid - 1;
            Min = min(Min, mid);
        }
        else {
            start = mid + 1;
        }
    }
    if (Min == LLONG_MAX) {
        cout << -1;
        return 0;
    }
    cout << Min;
    return 0;
}