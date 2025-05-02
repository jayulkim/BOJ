#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ull addmod(ull x, ull y, ull num) {
    if (x >= num - y) {
        return x - (num - y);
    }
    return x + y;
}
ull mulmod(ull x, ull y, ull num) {
    ll result = x * y - num * ull(1.L / num * x * y);
    if (result < 0) {
        return result + num;
    }
    if (result >= (ll)num) {
        return result - num;
    }
    return result;
}
ull powmod(ull x, ull y, ull num) {
    ll result = 1;
    x %= num;
    while (y) {
        if (y & 1) {
            result = mulmod(result, x, num);
        }
        x = mulmod(x, x, num);
        y >>= 1;
    }
    return result;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ll result = 1;
    if (n > m) {
        swap(n, m);
    }
    vector<bool>visited(n + 1, false);
    for (ll i = 2; i <= n; i++) {
        if (!visited[i]) {
            ll sum = 0;
            for (ll j = i * i; j <= n; j += i) {
                visited[j] = true;
            }
            for (ll j = i; j <= n; j *= i) {
                sum += (n / j) * (m / j);
            }
            result = mulmod(result, powmod(i, sum, 1000000007), 1000000007);
        }
    }
    cout << result;
    return 0;
}