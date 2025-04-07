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
    vector<pll>tree(n * 4 + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    function<pll(ll, ll, ll)> init = [&](ll start, ll end, ll idx) -> pll {
        if (start == end) {
            return tree[idx] = { v[start], start };
        }
        ll mid = (start + end) / 2;
        return tree[idx] = max(init(start, mid, idx * 2), init(mid + 1, end, idx * 2 + 1));
        };
    function<void(ll, ll, ll, ll, ll)> update = [&](ll start, ll end, ll idx, ll changeidx, ll change) -> void {
        if (start > changeidx || end < changeidx) {
            return;
        }
        if (start == end) {
            tree[idx] = { change, changeidx };
            return;
        }
        ll mid = (start + end) / 2;
        update(start, mid, idx * 2, changeidx, change);
        update(mid + 1, end, idx * 2 + 1, changeidx, change);
        tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
        };
    function<pll(ll, ll, ll, ll, ll)> query = [&](ll start, ll end, ll idx, ll left, ll right) -> pll {
        if (start > right || end < left) {
            return { 0, 0 };
        }
        if (left <= start && end <= right) {
            return tree[idx];
        }
        ll mid = (start + end) / 2;
        return max(query(start, mid, idx * 2, left, right), query(mid + 1, end, idx * 2 + 1, left, right));
        };
    init(1, n, 1);
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, n, 1, b, c);
        }
        else {
            pll temp = query(1, n, 1, b, c);
            update(1, n, 1, temp.second, 0);
            pll temptemp = query(1, n, 1, b, c);
            cout << temp.first + temptemp.first << '\n';
            update(1, n, 1, temp.second, temp.first);
        }
    }
    return 0;   
}