#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
ll eulerphi(ll n) {
    ll result = 1;
    for (ll i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                result *= i;
                n /= i;
            }
            result /= i;
            result *= (i - 1);
        }
    }
    if (n > 1) {
        result *= (n - 1);
    }
    return result;
}
ll powmod(ll x, ll y, ll num) {
    ll result = 1;
    while (y > 0) {
        if (y % 2) {
            if (result * x > num) {
                result = (result * x) % num + num;
            }
            else {
                result *= x;
            }
        }
        if (x * x > num) {
            x = (x * x) % num + num;
        }
        else {
            x *= x;
        }
        y /= 2;
    }
    return result;
}
ll query(ll n, ll m, ll mod) {
    if (m == 0) {
        return 1;
    }
    ll temp = query(n, m - 1, eulerphi(mod));
    return powmod(n, temp, mod);
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (1) {
        cin >> n;
        if (!n) {
            break;
        }
        cin >> m >> k;
        ll temp = powmod(10, k, LLONG_MAX);
        string str = to_string(query(n, m, 10000000) % temp);
        reverse(str.begin(), str.end());
        for (int i = k - 1; i >= 0; i--) {
            if (i >= str.length()) {
                cout << '0';
            }
            else {
                cout << str[i];
            }
        }
        cout << '\n';
    }
    return 0;
}