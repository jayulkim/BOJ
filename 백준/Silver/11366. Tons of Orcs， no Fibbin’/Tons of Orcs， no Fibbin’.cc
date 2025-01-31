#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (1) {
        cin >> n >> m >> k;
        if (!n && !m && !k) {
            break;
        }
        if (!n && !m) {
            cout << 0 << '\n';
        }
        else {
            ll temp = 0;
            for (int i = 0; i < k; i++) {
                temp = n + m;
                n = m;
                m = temp;
            }
            cout << temp << '\n';
        }
    }
    return 0;
}