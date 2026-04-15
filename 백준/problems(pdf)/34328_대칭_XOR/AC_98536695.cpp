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
    if (n == 1) {
        cout << 1;
        return 0;
    }
    ll temp = n + 2;
    while (temp > 1) {
        if (temp % 2) {
            cout << -1;
            return 0;
        }
        temp /= 2;
    }
    for (int i = 1; i <= n; i++) {
        cout << i << ' ';
    }
    return 0;
}