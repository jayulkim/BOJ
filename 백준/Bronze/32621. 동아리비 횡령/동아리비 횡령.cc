//사과 게임 탐색기
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
    ll idx = 0;
    string a = "";
    string b = "";
    bool find = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '+' && i + 1 < str.length()) {
            idx = i + 1;
            find = true;
        }
        if (isdigit(str[i])) {
            if (find) {
                b += str[i];
            }
            else {
                a += str[i];
            }
        }
    }
    if (str[0] != '0' && str[idx] != '0') {
        if (a == b && a != "" && b != "") {
            cout << "CUTE";
        }
        else {
            cout << "No Money";
        }
        return 0;
    }
    cout << "No Money";
    return 0;
}