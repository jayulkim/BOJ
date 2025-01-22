#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
vector<ll>v(500001);
vector<ll>tree(500001 * 4);
ll init(ll start, ll end, ll idx) {
    if (start == end) {
        return tree[idx] = v[start];
    }    
    ll mid = (start + end) / 2;
    return tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
}
void update(ll start, ll end, ll idx, ll changeidx, ll change) {
    if (changeidx > end || start > changeidx) {
        return;
    }
    if (start == end) {
        tree[idx] += change;
        return;
    }
    ll mid = (start + end) / 2;
    update(start, mid, idx * 2, changeidx, change);
    update(mid + 1, end, idx * 2 + 1, changeidx, change);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
ll query(ll start, ll end, ll idx, ll left, ll right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[idx];
    }
    ll mid = (start + end) / 2;
    return query(start, mid, idx * 2, left, right) + query(mid + 1, end, idx * 2 + 1, left, right);
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    init(1, n, 1);
    cin >> m;
    for (int i = 0; i < m; i++) {
        char c;
        ll a = 0, b = 0;
        cin >> c >> a >> b;
        if (c == 'R') {
            cout << query(1, n, 1, a, b) << '\n';
        }
        else {
            update(1, n, 1, a, b);
        }
    }
    return 0;
}