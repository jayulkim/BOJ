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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cout << eulerphi(n);
    return 0;
}