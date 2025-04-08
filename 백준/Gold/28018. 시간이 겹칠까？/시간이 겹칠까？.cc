//폰 코딩
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
    vector<ll>v(1000002, 0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v[a]++;
        v[b + 1]--;
    }
    vector<ll>vv(1000002, 0);
    vv[0] = v[0];
    for (int i = 1; i <= 1000001; i++) {
        vv[i] = vv[i - 1] + v[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll num = 0;
        cin >> num;
        cout << vv[num] << '\n';
    }
    return 0;
}