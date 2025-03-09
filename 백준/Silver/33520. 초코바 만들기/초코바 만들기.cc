#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll count = 0;
    ll c = 0, d = 0;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        c = max(c, a);
        d = max(d, b);
    }
    cout << c * d;
    return 0;
}