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
    vector<pll>v;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    map<ll, ll>Map;
    map<ll, ll>a;
    map<ll, ll>b;
    vector<ll>vv;
    vector<ll>vvv;
    for (auto& i : v) {
        Map[-(-i.first + i.second)]++;
        Map[(i.first + i.second)]++;
        if (!a[-(-i.first + i.second)]) {
            a[-(-i.first + i.second)]++;
            vv.push_back(-(-i.first + i.second));
        }
        if (!b[(i.first + i.second)]) {
            vvv.push_back((i.first + i.second));
            b[(i.first + i.second)]++;
        }
    }
    ll result = Map.size();
    sort(vvv.begin(), vvv.end());
    for (auto& i : vv) {
        if (upper_bound(vvv.begin(), vvv.end(), i) != vvv.end()) {
            result += vvv.size() - (upper_bound(vvv.begin(), vvv.end(), i) - vvv.begin());
        }
    }
    cout << result;
    return 0;
}