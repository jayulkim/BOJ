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
    ll num = 0;
    cin >> num;
    while (num--) {
        ll a = 0, b = 0, c = 0;
        cin >> n >> a >> b >> c;
        if (((n * a * b * c) - n * (a * b + b * c + a * c)) % (a * b + b * c + a * c) == 0 && ((n * a * b * c) - n * (a * b + b * c + a * c)) / (a * b + b * c + a * c) >= 0) {
            ll temp = n + ((n * a * b * c) - n * (a * b + b * c + a * c)) / (a * b + b * c + a * c);
            if (temp % a == 0 && temp % b == 0 && temp % c == 0) {
                cout << ((n * a * b * c) - n * (a * b + b * c + a * c)) / (a * b + b * c + a * c) << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        else {
            cout << -1 << '\n';
        }
    }
    return 0;
}