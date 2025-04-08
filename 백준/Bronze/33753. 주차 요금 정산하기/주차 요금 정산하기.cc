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
    cin >> n >> m >> k;
    ll num = 0;
    cin >> num;
    if (num <= 30) {
        cout << n;
        return 0;
    }
    num -= 30;
    cout << n + ((num + m - 1) / m) * k;
    return 0;   
}