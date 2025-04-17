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
    vector<pll>v;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    sort(v.begin(), v.end());
    function<ll(pll, pll)> getdist = [&](pll a, pll b) -> ll {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
        };
    function<ll(ll, ll)> dfs = [&](ll start, ll end) -> ll {
        if (start == end) {
            return 1e20;
        }
        if (end - start <= 2) {
            ll result = LLONG_MAX;
            for (int i = start; i + 1 <= end; i++) {
                for (int j = i + 1; j <= end; j++) {
                    result = min(result, getdist(v[i], v[j]));
                }
            }
            return result;
        }
        ll mid = (start + end) / 2;
        ll a = dfs(start, mid);
        ll b = dfs(mid + 1, end);
        ll d = min(a, b);
        ll c = LLONG_MAX;
        vector<pll>vv;
        for (int i = mid; i >= start; i--) {
            if ((v[mid].first - v[i].first) * (v[mid].first - v[i].first) >= d) {
                break;
            }
            vv.push_back({ v[i].second, v[i].first });
        }
        for (int i = mid + 1; i <= end; i++) {
            if ((v[mid].first - v[i].first) * (v[mid].first - v[i].first) >= d) {
                break;
            }
            vv.push_back({ v[i].second, v[i].first });
        }
        sort(vv.begin(), vv.end());
        for (int i = 0; i < vv.size(); i++) {
            for (int j = i + 1; j < vv.size(); j++) {
                if ((vv[j].first - vv[i].first) * (vv[j].first - vv[i].first) >= d) {
                    break;
                }
                c = min(c, getdist(vv[i], vv[j]));
            }
        }
        return min(c, d);
        };
    cout << dfs(0, n - 1);
    return 0;
}