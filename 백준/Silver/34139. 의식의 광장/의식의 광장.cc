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
    vector<lll>v;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v.push_back({ b, a, i });
    }
    sort(v.begin(), v.end(), greater<lll>());
    vector<ll>vv(m + 1, 0);
    ll temp = m;
    for (auto& [a, b, c] : v) {
        vv[c] = temp--;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < m; i++) {
        cout << vv[i] << ' ';
    }
    return 0; 
}