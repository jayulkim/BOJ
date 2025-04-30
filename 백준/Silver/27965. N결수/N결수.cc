//폰 코딩
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ll result = 0;
    for (ll i = 1; i <= n; i++) {
        ll count = 0;
        ll temp = i;
        while (temp > 0) {
            count++;
            temp /= 10;
            result *= 10;
        }
        result = ((result % m) + (i % m)) % m;
    }
    cout << result;
    return 0;
}