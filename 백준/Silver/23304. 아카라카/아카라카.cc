#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
string str = "";
bool result = true;
void akaraka(string str) {
    if (str.length() == 1) {
        result &= true;
        return;
    }
    string a = "", b = "";
    if (str.length() % 2) {
        for (int i = 0; i < str.length() / 2; i++) {
            a += str[i];
        }
        for (int i = str.length() / 2 + 1; i < str.length(); i++) {
            b += str[i];
        }
        for (int i = 0; i < a.length() / 2; i++) {
            if (a[i] != a[a.length() - 1 - i]) {
                result &= false;
            }
        }
        for (int i = 0; i < b.length(); i++) {
            if (b[i] != b[b.length() - 1 - i]) {
                result &= false;
            }
        }
        akaraka(a);
        akaraka(b);
    }
    else {
        for (int i = 0; i < str.length() / 2; i++) {
            a += str[i];
        }
        for (int i = str.length() / 2; i < str.length(); i++) {
            b += str[i];
        }
        for (int i = 0; i < a.length() / 2; i++) {
            if (a[i] != a[a.length() - 1 - i]) {
                result &= false;
            }
        }
        for (int i = 0; i < b.length(); i++) {
            if (b[i] != b[b.length() - 1 - i]) {
                result &= false;
            }
        }
        akaraka(a);
        akaraka(b);
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    akaraka(str);
    if (result) {
        cout << "AKARAKA";
    }
    else {
        cout << "IPSELENTI";
    }
    return 0;
}