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
    string str = "";
    cin >> str;
    ll result = 0;
    function<ll(ll, ll, ll)> powmod = [&](ll a, ll b, ll c) -> ll {
        ll result = 1;
        while (b) {
            if (b % 2) {
                result *= (a % c);
                result %= c;
            }
            a *= (a % c);
            a %= c;
            b /= 2;
        }
        return result;
        };
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'O') {
            result += powmod(2, i, 1e9 + 7);
            result %= 1000000007;
        }
    }
    cout << result;
    return 0;
}