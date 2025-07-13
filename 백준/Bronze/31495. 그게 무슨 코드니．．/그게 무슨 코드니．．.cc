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
    getline(cin, str);
    if (str[0] == '"' && str.back() == '"' && str.length() > 2) {
        for (int i = 1; i < str.length() - 1; i++) {
            cout << str[i];
        }
    }
    else {
        cout << "CE";
    }
    return 0;
 }