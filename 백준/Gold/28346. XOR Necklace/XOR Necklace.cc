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
        vector<ll>v;
        for (int i = 0; i < n; i++) {
            ll num = 0;
            cin >> num;
            v.push_back(num);
        }
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (v[i] ^ v[(i + 1) % n]);
        }
        cout << sum << '\n';
    }
    return 0;
}