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
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string str = "";
        getline(cin, str);
        str[0] = toupper(str[0]);
        cout << str << '\n';
    }
    return 0;
 }