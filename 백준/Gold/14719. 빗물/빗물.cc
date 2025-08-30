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
    cin >> n >> m;
    vector<vector<ll>>v(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i < m; i++) {
        ll num = 0;
        cin >> num;
        for (int j = 0; j < num; j++) {
            v[j][i] = 1;
        }
    }
    ll result = 0;
    for (int i = 0; i < n; i++) {
        ll find = -1;
        ll count = 0;
        for (int j = 0; j < m; j++) {
            if (v[i][j]) {
                if (find == -1) {
                    find = 0;
                }
                else if (!find) {
                    result += count;
                    count = 0;
                    find = 0;
                }
            }
            else {
                if (!find) {
                    count++;
                }
            }
        }
    }
    cout << result;
    return 0;
}