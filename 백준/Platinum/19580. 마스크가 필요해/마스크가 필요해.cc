#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
    vector<pll>v;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    map<ll, ll>Map;
    vector<pll>vv;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        vv.push_back({ a, b });
    }
    sort(all(v), greater<pll>());
    sort(all(vv), greater<pll>());
    ll count = 0;
    ll idx = 0;
    for (int i = 0; i < n; i++) {
        while (idx < m && v[i].first <= vv[idx].first) {
            Map[vv[idx].first] += vv[idx].second;
            idx++;
        }
        auto iter = Map.upper_bound(v[i].second);
        if (iter != Map.begin()) {
            iter = prev(iter);
            count++;
            Map[iter->first]--;
            if (!Map[iter->first]) {
                Map.erase(iter->first);
            }
        }
    }
    cout << count;
	return 0;
}