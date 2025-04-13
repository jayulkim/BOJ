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
    vector<ll>lazy(n * 4 + 1, 0);
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
    init(1, n, 1);
    function<void(ll, ll, ll)> updatelazy = [&](ll start, ll end, ll idx) -> void {
        if (lazy[idx]) {
            tree[idx] += (end - start + 1) * lazy[idx];
            if (start != end) {
                lazy[idx * 2] += lazy[idx];
                lazy[idx * 2 + 1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        };
    function<ll(ll, ll, ll, ll, ll)> query = [&](ll start, ll end, ll idx, ll left, ll right) -> ll {
        updatelazy(start, end, idx);
        if (start > right || end < left) {
            return 0;
        }
        if (left <= start && end <= right) {
            return tree[idx];
        }
        ll mid = (start + end) / 2;
        return query(start, mid, idx * 2, left, right) + query(mid + 1, end, idx * 2 + 1, left, right);
        };
    function<void(ll, ll, ll, ll, ll, ll)> update = [&](ll start, ll end, ll idx, ll left, ll right, ll change) -> void {
        updatelazy(start, end, idx);
        if (start > right || end < left) {
            return;
        }
        if (left <= start && end <= right) {
            tree[idx] += (end - start + 1) * change;
            if (start != end) {
                lazy[idx * 2] += change;
                lazy[idx * 2 + 1] += change;
            }
            return;
        }
        else {
            ll mid = (start + end) / 2;
            update(start, mid, idx * 2, left, right, change);
            update(mid + 1, end, idx * 2 + 1, left, right, change);
            tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
        }
        };
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0, c = 0, d = 0;
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update(1, n, 1, b, c, d);
        }
        else {
            cin >> b;
            cout << query(1, n, 1, b, b) << '\n';
        }
    }
    return 0;
}