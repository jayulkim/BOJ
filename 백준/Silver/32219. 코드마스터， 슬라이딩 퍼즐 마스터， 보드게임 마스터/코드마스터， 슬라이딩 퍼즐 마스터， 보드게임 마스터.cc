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
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n >> m;
        if (n != m) {
            cout << "jinseo" << '\n';
            cout << min(n, m) << ' ' << min(n, m) << '\n';
        }
        else {
            cout << "dohoon" << '\n';
        }
    }
    return 0;
}