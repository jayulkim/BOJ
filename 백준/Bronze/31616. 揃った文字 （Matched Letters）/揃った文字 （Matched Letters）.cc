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
    string str = "";
    cin >> str;
    for (int i = 0; i < n - 1; i++) {
        if (str[i] != str[i + 1]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
 }