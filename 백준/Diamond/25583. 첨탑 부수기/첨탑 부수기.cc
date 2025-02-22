#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
long long n = 0, m = 0, k = 0;
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
vector<ll>v;
ll query(ll n, ll mod) {
    if (mod == 1 || n < 0) {
        return 1;
    }
    ll temp = query(n - 1, eulerphi(mod));
    return powmod(v[n], temp, mod);
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    string str = "";
    cin >> str;
    if (n == 1 && m == 1) {
        cout << 0;
        return 0;
    }
    else if (n == 1) {
        cout << 1;
        return 0;
    }
    for (ll i = max((ll)2, (ll)n - 10000); i <= n; i++) {
        ll sum = 0;
        for (ll j = 1; j <= str.length(); j++) {
            if (str[(j * i) % 10] >= '1' && str[(j * i) % 10] <= '9') {
                sum += str[(j * i) % 10] - '0';
            }
            else if (str[(j * i) % 10] >= 'A' && str[(j * i) % 10] <= 'Z') {
                sum += str[(j * i) % 10] - 55;
            }
            else {
                sum += str[(j * i) % 10] - 61;
            }
        }
        v.push_back(sum * i);
    }
    cout << (unsigned long long)query(v.size() - 1, m) % m;
    return 0;
}