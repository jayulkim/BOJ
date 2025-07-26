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
        cin >> m;
        ll a = 1;
        for (int j = 2; j <= m; j++) {
            a *= j;
            a %= 10;
        }
        cout << a % 10 << '\n';
    }
    return 0;
}