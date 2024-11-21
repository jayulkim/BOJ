#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<pll>tree(4 * 100001, {0, 0});
vector<ll>v(100001);
pll init(ll start, ll end, ll idx) {
	if (start == end) {
		if (v[start] % 2) {
			tree[idx].first++;
			return tree[idx];
		}
		else {
			tree[idx].second++;
			return tree[idx];
		}
	}
	ll mid = (start + end) / 2;
	pll a = init(start, mid, idx * 2);
	pll b = init(mid + 1, end, idx * 2 + 1);
	return tree[idx] = { a.first + b.first, a.second + b.second };
}
void update(ll start, ll end, ll idx, ll changeidx, ll change) {
	if (start > changeidx || end < changeidx) {
		return;
	}
	if (start == end) {
		if (change % 2) {
			tree[idx] = { 1, 0 };
			return;
		}
		else {
			tree[idx] = { 0, 1 };
			return;
		}
	}
	ll mid = (start + end) / 2;
	update(start, mid, idx * 2, changeidx, change);
	update(mid + 1, end, idx * 2 + 1, changeidx, change);
	ll a = tree[idx * 2].first + tree[idx * 2 + 1].first;
	ll b = tree[idx * 2].second + tree[idx * 2 + 1].second;
	tree[idx] = { a, b };
}
pll query(ll start, ll end, ll idx, ll left, ll right) {
	if (end < left || start > right) {
		return { 0, 0 };
	}
	if (left <= start && end <= right) {
		return tree[idx];
	}
	ll mid = (start + end) / 2;
	pll a = query(start, mid, idx * 2, left, right);
	pll b = query(mid + 1, end, idx * 2 + 1, left, right);
	return { a.first + b.first, a.second + b.second };
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
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c);
		}
		else if (a == 2) {
			cout << query(1, n, 1, b, c).second << '\n';
		}
		else {
			cout << query(1, n, 1, b, c).first << '\n';
		}
	}
	return 0;
}