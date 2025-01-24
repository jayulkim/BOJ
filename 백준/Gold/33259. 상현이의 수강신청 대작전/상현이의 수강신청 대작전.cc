#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll dp[5001][5001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<pll>v;
    bool find = false;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v.push_back({ a, b });
        if (m >= b) {
            find = true;
        }
    }
    if (!find) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j >= v[i - 1].second) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1].second] + v[i - 1].first);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    vector<ll>vv;
    for(int i = n; i >= 1; i--) {
        if (dp[i][m] != dp[i - 1][m]) {
            vv.push_back(i);
            m -= v[i - 1].second;
        }
    }
    cout << vv.size() << '\n';
    sort(vv.begin(), vv.end());
    for (auto& i : vv) {
        cout << i << ' ';
    }
    return 0;
}