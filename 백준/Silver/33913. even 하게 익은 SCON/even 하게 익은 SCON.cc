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
    function<ll(ll, ll, ll)> mulmod = [&](ll a, ll b, ll c) -> ll {
        ll result = 0;
        while (b) {
            if (b % 2) {
                result += (a % c);
                result %= c;
            }
            a += (a % c);
            a %= c;
            b /= 2;
        }
        return result;
        };
    function<ll(ll, ll, ll)> powmod = [&](ll a, ll b, ll c) -> ll {
        ll result = 1;
        while (b) {
            if (b % 2) {
                result *= (a % c);
                result %= c;
            }
            a *= (a % c);
            a %= c;
            b /= 2;
        }
        return result;
        };
    cout << mulmod(powmod(26, n, 1000000007) + powmod(22, n, 1000000007), powmod(2, 1000000005, 1000000007), 1000000007);
    return 0; 
}