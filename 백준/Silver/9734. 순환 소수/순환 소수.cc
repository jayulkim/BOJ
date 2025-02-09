#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
ll gcd(ll a, ll b) {
    ll temp = a % b;
    while (temp > 0) {
        a = b;
        b = temp;
        temp = a % b;
    }
    return b;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str = "";
    while (cin >> str) {
        string up = "";
        string down = "";
        string minus = "";
        bool a = false, b = false, c = true;
        for (auto& i : str) {
            if (i == '.') {
                a = true;
            }
            else if (i == '(') {
                b = true;
                a = false;
                c = false;
            }
            else if (i != ')') {
                if (a) {
                    down += '0';
                }
                if (b) {
                    down += '9';
                }
                if (c) {
                    minus += i;
                }
                up += i;
            }
        }
        reverse(down.begin(), down.end());
        cout << str << " = " << (stoll(up) - stoll(minus)) / gcd((stoll(up) - stoll(minus)), stoll(down)) << " / " << stoll(down) / gcd((stoll(up) - stoll(minus)), stoll(down)) << '\n';
    }
    return 0;
}