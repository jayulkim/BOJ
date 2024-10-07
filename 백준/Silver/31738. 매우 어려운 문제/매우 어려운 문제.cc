#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie();
    ll n = 0, m = 0;
    cin >> n >> m;
    ll result = 1;
    for (ll i = 1; i <= min(n, m); i++) {
        result *= (i % m);
        result %= m;
    }
    cout << result;
    return 0;
}