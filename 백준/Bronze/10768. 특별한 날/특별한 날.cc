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
    if (n == 2) {
        if (m == 18) {
            cout << "Special";
        }
        else if (m < 18) {
            cout << "Before";
        }
        else {
            cout << "After";
        }
    }
    else if (n > 2) {
        cout << "After";
    }
    else if (n < 2) {
        cout << "Before";
    }
    return 0;
}