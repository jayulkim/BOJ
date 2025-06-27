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
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << ' ';
        }
        for (int j = 0; j <= i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    for (int i = 0; i < n; i++) {
        cout << '*';
    }
    cout << '\n';
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= i; j++) {
            cout << ' ';
        }
        for (int j = 0; j < n - i - 1; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}