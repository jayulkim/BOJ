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
    cin >> n >> m;
    vector<ll>v(10001, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll num = 0;
            cin >> num;
            v[num]++;
        }
    }
    if (m == 1) {
        cout << "YES";
        return 0;
    }
    if (m % 2) {
        ll a = 0;
        for (int i = 1; i <= 10000; i++) {
            if (v[i] % 2) {
                a++;
            }
        }
        if (a > n) {
            cout << "NO";
        }
        else {
            cout << "YES";
        }
    }
    else {
        for (int i = 1; i <= 10000; i++) {
            if (v[i] % 2) {
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }
    return 0; 
}