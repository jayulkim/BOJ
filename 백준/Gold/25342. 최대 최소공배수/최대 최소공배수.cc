//폰 코딩
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
    ll num = 0;
    cin >> num;
    function<ll(ll, ll)> gcd = [&](ll a, ll b) -> ll {
        ll temp = a % b;
        while (temp > 0) {
            a = b;
            b = temp;
            temp = a % b;
        }
        return b;
        };
    while (num--) {
        cin >> n;
        ll a = (n * (n - 1)) / gcd(n, n - 1);
        ll b = ((n - 1) * (n - 2)) / gcd(n - 1, n - 2);
        if (n == 3) {
            cout << 6 << '\n';
        }
        else {
             cout << max({(a * (n - 3)) / gcd(a, n - 3), (b * n) / gcd(b, n), (a * (n - 2)) / gcd(a, n - 2), (b * (n - 3)) / gcd(b, n - 3)}) << '\n';
        }
    }
    return 0;
}