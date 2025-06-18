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
    if (str.length() == 1) {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < str.length() - 1; i++) {
        ll a = 1, b = 1;
        for (int j = 0; j <= i; j++) {
            a *= str[j] - '0';
        }
        for (int j = i + 1; j < str.length(); j++) {
            b *= str[j] - '0';
        }
        if (a == b) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}