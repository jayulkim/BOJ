#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>tree(4 * 100001);
vector<ll>v(100001);
ll init(ll start, ll end, ll idx) {
	if (start == end) {
		if (v[start] < 0) {
			return tree[idx] = -1;
		}
		else if (v[start] > 0) {
			return tree[idx] = 1;
		}
		else {
			return tree[idx] = 0;
		}
	}
	ll mid = (start + end) / 2;
	return tree[idx] = init(start, mid, idx * 2) * init(mid + 1, end, idx * 2 + 1);
}
void update(ll start, ll end, ll idx, ll changeidx, ll change) {
	if (start > changeidx || end < changeidx) {
		return;
	}
	if (start == end) {
		if (change < 0) {
			tree[idx] = -1;
		}
		else if (change > 0) {
			tree[idx] = 1;
		}
		else {
			tree[idx] = 0;
		}
		return;
	}
	ll mid = (start + end) / 2;
	update(start, mid, idx * 2, changeidx, change);
	update(mid + 1, end, idx * 2 + 1, changeidx, change);
	tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
}
ll query(ll start, ll end, ll idx, ll left, ll right) {
	if (start > right || end < left) {
		return 1;
	}
	if (left <= start && end <= right) {
		return tree[idx];
	}
	ll mid = (start + end) / 2;
	return query(start, mid, idx * 2, left, right) * query(mid + 1, end, idx * 2 + 1, left, right);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> m) {
		string str = "";
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		init(1, n, 1);
		for (int i = 0; i < m; i++) {
			char command = '\0';
			ll a = 0, b = 0;
			cin >> command >> a >> b;
			if (command == 'C') {
				update(1, n, 1, a, b);
			}
			else {
				ll result = query(1, n, 1, a, b);
				if (result == 0) {
					str += '0';
				}
				else if (result > 0) {
					str += '+';
				}
				else {
					str += '-';
				}
			}
		}
		cout << str << '\n';
	}
	return 0;
}