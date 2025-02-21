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
vector<ll>v;
ll query(ll n, ll mod) {
    if (n == 0) {
        return v[0];
    }
    ll temp = query(n - 1, eulerphi(mod));
    return powmod(v[n], temp, mod);
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (n--) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            ll num = 0;
            cin >> num;
            v.push_back(num);
        }
        reverse(v.begin(), v.end());
        cout << query(k - 1, m) % m << '\n';
        vector<ll>().swap(v);
    }
    return 0;
}