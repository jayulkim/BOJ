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
    ll a = 0, b = 0, c = 0, d = 0;
    cin >> a >> b >> c >> d;
    if (a + b + c + d + 300 <= 1800) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
 }