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
    ld result = 0;
    for (int i = 0; i < n; i++) {
        ld a = 0;
        cin >> a;
        result += a * a * a;
    }
    cout << fixed;
    cout.precision(30);
    cout << cbrt(result);
    return 0;
 }