#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>tree(1000001 * 4);
void update(ll start, ll end, ll idx, ll changeidx, ll change) {
	if (start > changeidx || end < changeidx) {
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
	if (end < left || start > right) {
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
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c);
		}
		else {
			cout << query(1, n, 1, b, c) << '\n';
		}
	}
	return 0;
}