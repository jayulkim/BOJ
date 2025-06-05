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
    cin >> n >> m;
    string str = "";
    cin >> str;
    for (int i = 0; i < str.length() && m > 0; i++) {
        if ('Z' - str[i] + 1 <= m && str[i] > 'A') {
            m -= 'Z' - str[i] + 1;
            str[i] = 'A';
        }
    }
    m %= 26;
    str.back() = (((str.back() - 'A') + m) % 26) + 'A';
    cout << str;
    return 0;
}