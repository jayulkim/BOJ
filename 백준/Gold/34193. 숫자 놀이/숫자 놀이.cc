#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
typedef pair<ll, string> pls;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        if (a >= 2) {
            if ((2 * b) % a == 0 && ((2 * b) / a) % 2 == 0) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            ll count = 0;
            for (int j = 1; j * j <= a + b; j++) {
                if ((a + b) % j == 0) {
                    if (j * j == a + b) {
                        count++;
                    }
                    else {
                        count += 2;
                    }
                }
            }
            cout << count << '\n';
        }
    }
    return 0;
}