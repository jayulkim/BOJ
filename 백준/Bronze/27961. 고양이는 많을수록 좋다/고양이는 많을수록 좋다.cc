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
    if (!n) {
        cout << 0;
        return 0;
    }
    ll count = 0;
    while (n > 1) {
        n++;
        n /= 2;
        count++;
    }
    cout << count + 1;
    return 0;
}