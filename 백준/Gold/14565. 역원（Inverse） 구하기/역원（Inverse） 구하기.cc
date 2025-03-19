#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll eea(ll a, ll b) {
    ll r1 = a, r2 = b, s1 = 1, t1 = 0, s2 = 0, t2 = 1;
    while (r2 > 0) {
        ll x = r1 / r2;
        ll y = r1 % r2;
        r1 = r2;
        r2 = y;
        ll s = s1 - x * s2;
        s1 = s2;
        s2 = s;
        ll t = t1 - x * t2;
        t1 = t2;
        t2 = t;
    }
    return t1;
}
ll gcd(ll a, ll b) {
    ll temp = a % b;
    while (temp > 0) {
        a = b;
        b = temp;
        temp = a % b;
    }
    return b;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    if (gcd(n, m) != 1) {
        cout << n - m << ' ' << -1;
        return 0;
    }
    cout << n - m << ' ' << (eea(n, m) + n) % n;
    return 0;
}