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
    vector<ll>v(1000001, 0);
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            v[j]++;
        }
    }
    cin >> n >> m;
    vector<ll>vv(n + 1, 0);
    vector<ll>tree(4 * n + 1, 0);
    map<ll, ll>aa;
    for (int i = 1; i <= n; i++) {
        cin >> vv[i];
        if (vv[i] > 2) {
            aa[i]++;
        }
    }
    function<ll(ll, ll, ll)> init = [&](ll start, ll end, ll idx) -> ll {
        if (start == end) {
            return tree[idx] = vv[start];
        }
        ll mid = (start + end) / 2;
        return tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
        };
    init(1, n, 1);
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
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        if (a == 1) {
            vector<ll>vvv;
            for (auto& j : aa) {
                if (b <= j.first && j.first <= c) {
                    update(1, n, 1, j.first, v[vv[j.first]]);
                    vv[j.first] = v[vv[j.first]];
                    if (vv[j.first] <= 2) {
                        vvv.push_back(j.first);
                    }
                }
            }
            for (auto& j : vvv) {
                aa.erase(aa.find(j));
            }
        }
        else {
            cout << query(1, n, 1, b, c) << '\n';
        }
    }
    return 0;
}