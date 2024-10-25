#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<ll>mon;
    vector<ll>wep;
    for (int i = 0; i < n; i++) {
        ll command = 0, a = 0;
        cin >> command >> a;
        if (command == 1) {
            mon.push_back(a);
        }
        else {
            wep.push_back(a);
        }
    }
    sort(mon.begin(), mon.end());
    sort(wep.begin(), wep.end());
    ll idx = 0;
    for (int i = 0; i < mon.size(); i++) {
        while (idx < wep.size() && m <= mon[i]) {
            m *= wep[idx++];
        }
        if (m <= mon[i]) {
            cout << i + idx;
            return 0;
        }
        else {
            m += mon[i];
        }
    }
    cout << n;
    return 0;
}