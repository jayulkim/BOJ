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
    string temp = "";
    ll result = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ',') {
            result += stoll(temp);
            temp = "";
        }
        else {
            temp += str[i];
        }
    }
    result += stoll(temp);
    cout << result;
    return 0;
 }