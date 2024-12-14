#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>v(100001);
vector<ll>tree(100001 * 4);
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
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n >> m >> k;
		for (int i = 0; i < m + k; i++) {
			char c = '\0';
			ll a = 0, b = 0;
			cin >> c >> a >> b;
			if (c == 'P') {
				update(1, n, 1, a, b);
			}
			else if (c == 'Q') {
				cout << query(1, n, 1, a, b) << '\n';
			}
		}
		vector<ll>(100001, 0).swap(v);
		vector<ll>(100001 * 4, 0).swap(tree);
	}
	return 0;
}