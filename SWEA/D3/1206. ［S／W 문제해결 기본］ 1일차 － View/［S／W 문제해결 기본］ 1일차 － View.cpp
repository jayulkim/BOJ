#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef tuple<ll, ll, ll, ll, ll> lllll;
typedef tuple<ll, ll, vector<ll>> llv;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll num = 10;
    ll count = 1;
    while (num--) {
        cin >> n;
        vector<vector<ll>>v(256, vector<ll>(n + 1, 0));
        vector<ll>vv(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> vv[i];
            for (int j = 1; j <= vv[i]; j++) {
                v[j][i] = 1;
            }
        }
        ll result = 0;
        for (int i = 3; i <= n - 2; i++) {
            for (int j = 1; j <= vv[i]; j++) {
                if (!v[j][i - 1] && !v[j][i - 2] && !v[j][i + 1] && !v[j][i + 2]) {
                    result++;
                }
            }
        }
        cout << '#' << count++ << ' ' << result << '\n';
    }
    return 0;
 }