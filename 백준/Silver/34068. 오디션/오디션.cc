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
    vector<ll>v(n + 1, 0);
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v[a]++;
    }
    vector<ll>vv;
    for (int i = 1; i <= n; i++) {
        vv.push_back(v[i]);
    }
    sort(vv.begin(), vv.end());
    ll result = 0;
    ll temp = 0;
    for (int i = 1; i < n; i++) {
        temp = vv[i - 1] + 1;
        if (temp - vv[i] > 0) {
            result += max((ll)0, temp - vv[i]);
            vv[i] = vv[i - 1] + 1;
        }
    }
    cout << result;
    return 0;
 }