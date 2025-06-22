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
    while (1) {
        string str = "";
        cin >> str;
        if (str == "#") {
            break;
        }
        map<char, ll>Map;
        Map['-'] = 0;
        Map['\\'] = 1;
        Map['('] = 2;
        Map['@'] = 3;
        Map['?'] = 4;
        Map['>'] = 5;
        Map['&'] = 6;
        Map['%'] = 7;
        Map['/'] = -1;
        ll result = 0;
        for (int i = 0; i < str.length(); i++) {
            ll temp = 1;
            for (int j = 0; j < str.length() - i - 1; j++) {
                temp *= 8;
            }
            result += temp * Map[str[i]];
        }
        cout << result << '\n';
    }
    return 0;
}