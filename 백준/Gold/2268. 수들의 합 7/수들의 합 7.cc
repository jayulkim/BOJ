#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
vector<ll>tree(4000001);
ll n = 0, m = 0, k = 0;
void update(ll start, ll end, ll idx, ll changeidx, ll change) {
	if (changeidx < start || changeidx > end) {
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
}
ll query(ll start, ll end, ll idx, ll left, ll right) {
	if (start > right || end < left) {
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
	ll n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (!a) {
			if (b > c) {
				swap(b, c);
			}
			cout << query(1, n, 1, b, c) << '\n';
		}
		else {
			update(1, n, 1, b, c);
		}
	}
	return 0;
}