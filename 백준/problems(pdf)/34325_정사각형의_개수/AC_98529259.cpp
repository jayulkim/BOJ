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
    ll mod = 1000000007;
    function<ll(ll, ll, ll)> powmod = [&](ll a, ll b, ll c) -> ll {
        ll result = 1;
        while (b > 0) {
            if (b % 2) {
                result *= (a % mod);
                result %= mod;
            }
            a *= (a % mod);
            a %= mod;
            b /= 2;
        }
        return result;
        };
    ll result = 0;
    for (ll i = 1; i <= n; i++) {
        if (i % 2) {
            result += (powmod(m, (n - i + 1), mod) * (powmod(i, 2, mod) + (4 * powmod((i - 1) / 2, 2, mod)) % mod) % mod) % mod;
        }
        else {
            result += (powmod(m, (n - i + 1), mod) * (powmod(i, 2, mod) + (4 * (powmod((i - 2) / 2, 2, mod) + (i - 2) / 2))) % mod) % mod;
        }
        result %= mod;
    }
    cout << result;
    return 0;
}