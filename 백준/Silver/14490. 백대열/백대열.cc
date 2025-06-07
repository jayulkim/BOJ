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
    string str = "";
    cin >> str;
    string a = "", b = "";
    ll idx = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ':') {
            idx = i;
            break;
        }
        a += str[i];
    }
    for (int i = idx + 1; i < str.length(); i++) {
        b += str[i];
    }
    function<ll(ll, ll)> gcd = [&](ll a, ll b) -> ll {
        ll temp = a % b;
        while (temp > 0) {
            a = b;
            b = temp;
            temp = a % b;
        }
        return b;
        };
    cout << stoll(a) / gcd(stoll(a), stoll(b)) << ':' << stoll(b) / gcd(stoll(a), stoll(b));
    return 0;
}