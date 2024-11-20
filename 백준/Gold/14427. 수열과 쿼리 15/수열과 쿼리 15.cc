#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<pll>tree(4 * 100001, { LLONG_MAX, 0 });
vector<pll>v(100001);
pll init(ll start, ll end, ll idx) {
	if (start == end) {
		return tree[idx] = v[start];
	}
	ll mid = (start + end) / 2;
	return tree[idx] = min(init(start, mid, idx * 2), init(mid + 1, end, idx * 2 + 1));
}
void update(ll start, ll end, ll idx, ll changeidx, ll change) {
	if (start > changeidx || changeidx > end) {
		return;
	}
	if (start == end) {
		tree[idx] = { change, changeidx };
		return;
	}
	ll mid = (start + end) / 2;
	update(start, mid, idx * 2, changeidx, change);
	update(mid + 1, end, idx * 2 + 1, changeidx, change);
	tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll num = 0;
		cin >> num;
		v[i] = { num, i };
	}
	init(1, n, 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			update(1, n, 1, b, c);
		}
		else {
			cout << tree[1].second << '\n';
		}
	}
	return 0;
}