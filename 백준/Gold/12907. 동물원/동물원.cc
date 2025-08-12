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
    vector<ll>v(41, 0);
    vector<ll>vv;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        v[num]++;
        vv.push_back(num);
    }
    sort(vv.begin(), vv.end());
    for (int i = 0; i <= vv.back(); i++) {
        if (v[i] > 2) {
            cout << 0;
            return 0;
        }
        if (i) {
            if (v[i] > v[i - 1]) {
                cout << 0;
                return 0;
            }
        }
    }
    if (v[0] == 1) {
        for (int i = 1; i < vv.size(); i++) {
            if (vv[i] != vv[i - 1] + 1) {
                cout << 0;
                return 0;
            }
        }
        cout << 2;
    }
    else if (v[0] == 2) {
        vv.erase(unique(vv.begin(), vv.end()), vv.end());
        for (int i = 1; i < vv.size(); i++) {
            if (vv[i] != vv[i - 1] + 1) {
                cout << 0;
                return 0;
            }
        }
        ll result = 2;
        for (int i = 1; i <= 40; i++) {
            if (v[i]) {
                result *= 2;
            }
            if (v[i] == 1) {
                break;
            }
        }
        cout << result;
    }
    else {
        cout << 0;
    }
    return 0; 
}