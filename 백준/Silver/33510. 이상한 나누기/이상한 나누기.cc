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
    cin >> n;
    string str = "";
    cin >> str;
    bool find = false;
    ll count = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        if (i == 0 && str[i] == '1') {
            break;
        }
        if (str[i] == '1') {
            if (!find) {
                count++;
                find = true;
            }
        }
        else {
            if (find) {
                str[i] = '1';
                i++;
                find = false;
            }
        }
    }
    cout << count;
    return 0;
}