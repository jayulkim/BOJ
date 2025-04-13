#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>v(1000001);
vector<ll>tree(1000001 * 4 + 1);
vector<ll>lazy(1000001 * 4 + 1, 0);
ll init(ll start, ll end, ll idx) {
    if (start == end) {
        return tree[idx] = v[start];
    }
    ll mid = (start + end) / 2;
    return tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
}
void updatelazy(ll start, ll end, ll idx) {
    if (lazy[idx]) {
        tree[idx] += (end - start + 1) * lazy[idx];
        if (start != end) {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}
ll query(ll start, ll end, ll idx, ll left, ll right) {
    updatelazy(start, end, idx);
    if (start > right || end < left) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[idx];
    }
    ll mid = (start + end) / 2;
    return query(start, mid, idx * 2, left, right) + query(mid + 1, end, idx * 2 + 1, left, right);
}
void update(ll start, ll end, ll idx, ll left, ll right, ll change) {
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
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    init(1, n, 1);
    for (int i = 0; i < m + k; i++) {
        ll a = 0, b = 0, c = 0, d = 0;
        cin >> a;
        if (a == 2) {
            cin >> b >> c >> d;
            update(1, n, 1, b, c, d);
        }
        else {
            cin >> b >> c;
            cout << query(1, n, 1, b, c) << '\n';
        }
    }
    return 0;
}