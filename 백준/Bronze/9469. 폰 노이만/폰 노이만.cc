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
    cin >> n;
    for (int i = 0; i < n; i++) {
        ld a = 0, b = 0, c = 0, d = 0, e = 0;
        cin >> a >> b >> c >> d >> e;
        cout << a << ' ' << e * b / (c + d) << '\n';
    }
    return 0;
}