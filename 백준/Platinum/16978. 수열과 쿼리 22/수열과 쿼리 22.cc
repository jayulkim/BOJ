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
    vector<ll>v(n + 1);
    vector<ll>tree(n * 4 + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    function<ll(ll, ll, ll)> init = [&](ll start, ll end, ll idx) -> ll {
        if (start == end) {
            return tree[idx] = v[start];
        }
        ll mid = (start + end) / 2;
        return tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
        };
    function<void(ll, ll, ll, ll, ll)> update = [&](ll start, ll end, ll idx, ll changeidx, ll change) -> void {
        if (start > changeidx || end < changeidx) {
            return;
        }
        if (start == end) {
            tree[idx] = change;
            return;
        }
        ll mid = (start + end) / 2;
        update(start, mid, idx * 2, changeidx, change);
        update(mid + 1, end, idx * 2 + 1, changeidx, change);
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
        };
    function<ll(ll, ll, ll, ll, ll)> query = [&](ll start, ll end, ll idx, ll left, ll right) -> ll {
        if (start > right || end < left) {
            return 0;
        }
        if (left <= start && end <= right) {
            return tree[idx];
        }
        ll mid = (start + end) / 2;
        return query(start, mid, idx * 2, left, right) + query(mid + 1, end, idx * 2 + 1, left, right);
        };
    init(1, n, 1);
    cin >> m;
    vector<pll>vv;
    map<ll, vector<lll>>Map;
    ll Mapid = 0;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0, c = 0, d = 0;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            vv.push_back({ b, c });
        }
        else {
            cin >> b >> c >> d;
            Map[b].push_back({ i, c, d });
        }
    }
    vector<pll>result;
    for (int i = 0; i <= vv.size(); i++) {
        if (i) {
            update(1, n, 1, vv[i - 1].first, vv[i - 1].second);
        }
        if (Map[i].size()) {
            for (auto& [a, b, c] : Map[i]) {
                result.push_back({ a, query(1, n, 1, b, c) });
            }
        }
    }
    sort(result.begin(), result.end());
    for (auto& i : result) {
        cout << i.second << '\n';
    }
    return 0;   
}