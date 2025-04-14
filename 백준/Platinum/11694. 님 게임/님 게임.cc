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
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        result ^= num;
        v.push_back(num);
        if (n == 1) {
            if (num == 1) {
                cout << "cubelover";
            }
            else {
                cout << "koosaga";
            }
            return 0;
        }
    }
    bool find = false;
    for (auto& i : v) {
        if (i != 1) {
            find = true;
            break;
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
    if (n == 2 && (v[0] == 1 || v[1] == 1)) {
        cout << "koosaga";
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