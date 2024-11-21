#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>tree(4 * 1000001, 0);
void update(ll start, ll end, ll idx, ll degree, ll command) {
	if (start > degree || end < degree) {
		return;
	}
	if (start == end) {
		tree[idx] += command;
		return;
	}
	ll mid = (start + end) / 2;
	update(start, mid, idx * 2, degree, command);
	update(mid + 1, end, idx * 2 + 1, degree, command);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
ll num = 0, result = 0;
void query(ll start, ll end, ll idx) {
	if (start == end) {
		if (num <= tree[idx]) {
			result = start;
		}
		return;
	}
	ll mid = (start + end) / 2;
	if (tree[idx * 2] >= num) {
		query(start, mid, idx * 2);
	}
	else {
		num -= tree[idx * 2];
		query(mid + 1, end, idx * 2 + 1);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a;
		if (a == 1) {
			cin >> b;
			num = b;
			query(1, 1000000, 1);
			cout << result << '\n';
			update(1, 1000000, 1, result, -1);
			result = 0;
		}
		else {
			cin >> b >> c;
			update(1, 1000000, 1, b, c);
		}
	}
	return 0;
}