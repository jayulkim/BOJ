#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll result = 0;
    vector<ll>v;
    bool find = false;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        result ^= num;
        if (num != 1) {
            find = true;
        }
    }
    if (!find) {
        if (n % 2) {
            cout << "cubelover";
        }
        else {
            cout << "koosaga";
        }
        return 0;
    }
    if (!result) {
        cout << "cubelover";
    }
    else {
        cout << "koosaga";
    }
    return 0;
}