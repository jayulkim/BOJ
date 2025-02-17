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
        cin >> n >> m;
        ll a = 0, b = 1;
        while (1) {
            ll temp = a + b;
            if (temp <= n && b <= m) {
                a = b;
                b = temp;
            }
            else {
                break;
            }
        }
        cout << b << ' ' << a << '\n';
    }
    return 0;
}