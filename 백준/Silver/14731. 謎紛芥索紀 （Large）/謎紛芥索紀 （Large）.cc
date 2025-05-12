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
    cin >> n;
    ll result = 0;
    function<ll(ll, ll, ll)> addmod = [&](ll x, ll y, ll num) -> ll {
        if (x >= num - y) {
            return x - (num - y);
        }
        return x + y;
        };
    function<ll(ll, ll, ll)> mulmod = [&](ll x, ll y, ll num) -> ll {
        ll result = 0;
        while (y > 0) {
            if (y & 1) {
                result = addmod(result, x, num);
            }
            x = addmod(x, x, num);
            y >>= 1;
        }
        return result;
        };
    function<ll(ll, ll, ll)> powmod = [&](ll x, ll y, ll num) -> ll {
        ll result = 1;
        while (y > 0) {
            if (y & 1) {
                result = mulmod(result, x, num);
            }
            x = mulmod(x, x, num);
            y >>= 1;
        }
        return result;
        };    
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        result = addmod(result, mulmod(mulmod(a, b, 1000000007), powmod(2, b - 1, 1000000007), 1000000007), 1000000007);
    }   
    cout << result;
    return 0;

}