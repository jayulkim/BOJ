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
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n;
        string str = "";
        cin >> str;
        ll idx = -1;
        bool find = false;
        for (int i = 0; i < n * 2 + 1; i++) {
            if (str[i] == '-' && idx == -1) {
                idx = i;
            }
            if (idx != -1 && i > idx + 1 && isdigit(str[i]) && str[i] != '0') {
                find = true;
                cout << "NO\n";
                break;
            }
        }
        if (!find) {
            cout << "YES\n";
        }
    }
    return 0; 
}