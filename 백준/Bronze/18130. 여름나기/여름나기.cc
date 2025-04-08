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
    ll aa = 0, bb = 0, cc = 0;
    ll result = 0;
    ll Min = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        ll temp = m / b;
        if (m % b == 0) {
            temp--;
        }
        if (Min > a + ((temp * (temp + 1)) / 2) * c) {
            Min = a + ((temp * (temp + 1)) / 2) * c;
            result = i + 1;
        }
    } 
    cout << result << ' ' << Min;
    return 0;   
}