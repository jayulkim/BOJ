#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll addmod(ll x, ll y, ll num) {
    if (x >= num - y) {
        return x - (num - y);
    }
    return x + y;
}
ll mulmod(ll x, ll y, ll num) {
    ll result = 0;
    while (y > 0) {
        if (y % 2) {
            result = addmod(result, x, num);
        }
        x = addmod(x, x, num);
        y /= 2;
    }
    return result;
}
ll powmod(ll x, ll y, ll num) {
    ll result = 1;
    while (y > 0) {
        if (y % 2) {
            result = mulmod(result, x, num);
        }
        x = mulmod(x, x, num);
        y /= 2;
    }
    return result;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cout << (powmod(3, n - 1, 1000000009) - powmod(3, n - 2, 1000000009) + 1000000009) % 1000000009; 
    return 0;
}