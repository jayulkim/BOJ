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
    cin >> n >> m >> k;
    vector<ll>v(5, 0);
    vector<vector<ll>>dp(5, vector<ll>(5, 0));
    for (int i = 0; i < n; i++) {
        vector<ll>temp;
        for (int j = 1; j <= 4; j++) {
            ll num = 0;
            cin >> num;
            temp.push_back(num);
            dp[num][j]++;
        }
        for (auto& j : temp) {
            ll num = 0;
            cin >> num;
            v[j] += num;
        }
    }
    function<bool(const pll&, const pll&)> compare = [&](const pll& a, const pll& b) -> bool {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
        };
    for (int i = -100; i <= 100; i++) {
        for (int j = i; j <= 100; j++) {
            for (int o = j; o <= 100; o++) {
                ll u = -(i + j + o);
                if (u <= 100 && u >= -100) {
                    vector<ll>vvv = { i, j, o, u };
                    sort(vvv.begin(), vvv.end(), greater<ll>());
                    vector<ll>temp = v;
                    for (int g = 1; g <= 4; g++) {
                        for (int f = 1; f <= 4; f++) {
                            temp[g] += dp[g][f] * vvv[f - 1];
                        }
                    }
                    vector<pll>vvvv;
                    for (int g = 1; g <= 4; g++) {
                        vvvv.push_back({ temp[g], g });
                    }
                    sort(vvvv.begin(), vvvv.end(), compare);
                    if (vvvv[k - 1].second == m) {
                        for (auto& g : vvv) {
                            cout << g << ' ';
                        }
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1;
    return 0;
}