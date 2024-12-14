#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>v(50001);
vector<ll>mintree(50001 * 4);
vector<ll>maxtree(50001 * 4);
ll mininit(ll start, ll end, ll idx) {
	if (start == end) {
		return mintree[idx] = v[start];
	}
	ll mid = (start + end) / 2;
	return mintree[idx] = min(mininit(start, mid, idx * 2), mininit(mid + 1, end, idx * 2 + 1));
}
ll maxinit(ll start, ll end, ll idx) {
	if (start == end) {
		return maxtree[idx] = v[start];
	}
	ll mid = (start + end) / 2;
	return maxtree[idx] = max(maxinit(start, mid, idx * 2), maxinit(mid + 1, end, idx * 2 + 1));
}
ll minquery(ll start, ll end, ll idx, ll left, ll right) {
	if (start > right || end < left) {
		return LLONG_MAX;
	}
	if (left <= start && end <= right) {
		return mintree[idx];
	}
	ll mid = (start + end) / 2;
	return min(minquery(start, mid, idx * 2, left, right), minquery(mid + 1, end, idx * 2 + 1, left, right));
}
ll maxquery(ll start, ll end, ll idx, ll left, ll right) {
	if (start > right || end < left) {
		return 0;
	}
	if (left <= start && end <= right) {
		return maxtree[idx];
	}
	ll mid = (start + end) / 2;
	return max(maxquery(start, mid, idx * 2, left, right), maxquery(mid + 1, end, idx * 2 + 1, left, right));
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	mininit(1, n, 1);
	maxinit(1, n, 1);
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		cout << maxquery(1, n, 1, a, b) - minquery(1, n, 1, a, b) << '\n';
	}
	return 0;
}