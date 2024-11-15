#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
#define mod 1000000007
vector<ll>tree(4000001);
vector<ll>v(1000001);
ll n = 0, m = 0, k = 0;
ll init(ll start, ll end, ll idx) {
	if (start == end) {
		return tree[idx] = v[start];
	}
	ll mid = (start + end) / 2;
	return tree[idx] = ((init(start, mid, idx * 2) % mod) * (init(mid + 1, end, idx * 2 + 1) % mod)) % mod;
}
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
	tree[idx] = ((tree[idx * 2] % mod) * (tree[idx * 2 + 1] % mod)) % mod;
}
ll mul(ll start, ll end, ll idx, ll left, ll right) {
	if (left > end || right < start) {
		return 1;
	}
	if (left <= start && end <= right) {
		return tree[idx] % mod;
	}
	ll mid = (start + end) / 2;
	return ((mul(start, mid, idx * 2, left, right) % mod) * (mul(mid + 1, end, idx * 2 + 1, left, right))) % mod;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	init(1, n, 1);
	for (int i = 0; i < m + k; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c);
		}
		else {
			cout << mul(1, n, 1, b, c) << '\n';
		}
	}
	return 0;
}