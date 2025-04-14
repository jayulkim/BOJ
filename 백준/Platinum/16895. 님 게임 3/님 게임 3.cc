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
    vector<ll>v;
    ll result = 0;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
        result ^= num;
    }
    if (!result) {
        cout << 0;
        return 0;
    }
    ll count = 0;
    for (int i = 0; i < n; i++) {
        result ^= v[i];
        for (int j = 0; j <= v[i]; j++) {
            result ^= (v[i] - j);
            if (!result) {
                count++;
            }
            result ^= (v[i] - j);
        }
        result ^= v[i];
    }
    cout << count;
    return 0;
}