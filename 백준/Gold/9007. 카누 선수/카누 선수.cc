#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n >> m;
        vector<vector<ll>>v(4, vector<ll>());
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < m; j++) {
                ll num = 0;
                cin >> num;
                v[i].push_back(num);
            }
        }
        vector<ll>sum;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                sum.push_back(v[2][i] + v[3][j]);
            }
        }
        ll Min = LLONG_MAX;
        ll result = LLONG_MAX;
        sort(sum.begin(), sum.end());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ll temp = v[0][i] + v[1][j];
                ll idx = lower_bound(sum.begin(), sum.end(), n - temp) - sum.begin();
                if (idx == sum.size()) {
                    idx--;
                }
                if (Min > llabs(n - (temp + sum[idx]))) {
                    Min = llabs(n - (temp + sum[idx]));
                    result = temp + sum[idx];
                }
                else if (Min == llabs(n - (temp + sum[idx]))) {
                    result = min(result, temp + sum[idx]);
                }
                if (idx - 1 >= 0) {
                    idx--;
                    if (Min > llabs(n - (temp + sum[idx]))) {
                        Min = llabs(n - (temp + sum[idx]));
                        result = temp + sum[idx];
                    }
                    else if (Min == llabs(n - (temp + sum[idx]))) {
                        result = min(result, temp + sum[idx]);
                    }
                }
            }
        }
        cout << result << '\n';
    }
    return 0;
}