#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str = "";
    cin >> str;
    ll k = 0, s = 0, a = 0;
    for (auto& i : str) {
        if (i == 'K') {
            k++;
        }
        else if (i == 'S') {
            s++;
        }
        else if (i == 'A') {
            a++;
        }
    }
    ll len = 0;
    while (1) {
        if (!k) {
            break;
        }
        k--;
        len++;
        if (!s) {
            break;
        }
        s--;
        len++;
        if (!a) {
            break;
        }
        a--;
        len++;
    }
    string temp = "";
    for (int i = 0; i < len; i++) {
        if (i % 3 == 0) {
            temp += 'K';
        }
        else if (i % 3 == 1) {
            temp += 'S';
        }
        else {
            temp += 'A';
        }
    }
    ll result = 0;
    ll idx = temp.length() - 1;
    for (int i = str.length() - 1; i >= 0 && idx >= 0; i--) {
        if (str[i] == temp[idx]) {
            idx--;
            result++;
        }
    }
    cout << str.length() - result;
    return 0;
}