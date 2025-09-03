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
    cin >> n >> k;
    if (k == n) {
        cout << k << ' ';
        for (int i = 1; i <= k - 1; i++) {
            cout << i << ' ';
        }
        return 0;
    }
    if (k >= 4 && n == k + 1) {
        cout << 1 << ' ';
        cout << k << ' ';
        for (int i = 3; i <= k - 1; i++) {
            cout << i << ' ';
        }
        cout << 2 << ' ' << k + 1;
    }
    else if (k + 1 < n) {
        cout << k << ' ';
        for (int i = k + 1; i <= n; i++) {
            if (i != k + 2) {
                cout << i << ' ';
            }
        }
        cout << k + 2 << ' ';
        for (int i = 1; i <= k - 1; i++) {
            cout << i << ' ';
        }
    }
    else {
        cout << -1;
    }
    return 0;
}