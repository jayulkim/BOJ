#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
vector<ll>v;
ll result = 0;
ll a = 0, b = 0;
ll partition(ll start, ll end) {
	ll x = v[end];
	ll idx = start - 1;
	for (int j = start; j < end; j++) {
		if (v[j] <= x) {
			idx++;
			swap(v[idx], v[j]);
			result++;
			if (result == k) {
				a = min(v[idx], v[j]);
				b = max(v[idx], v[j]);
			}
		}
	}
	if (idx + 1 != end) {
		swap(v[idx + 1], v[end]);
		result++;
		if (result == k) {
			a = min(v[idx + 1], v[end]);
			b = max(v[idx + 1], v[end]);
		}
	}
	return idx + 1;
}
ll select(ll start, ll end, ll count) {
	if (start == end) {
		return v[start];
	}
	ll temp = partition(start, end);
	ll k = temp - start + 1;
	if (count < k) {
		if (temp - 1 < v.size() && temp - 1 >= 0) {
			return select(start, temp - 1, count);
		}
	}
	else if (count == k) {
		if (temp < v.size() && temp >= 0) {
			return v[temp];
		}
	}
	else {
		if (temp + 1 < v.size() && temp + 1 >= 0) {
			return select(temp + 1, end, count - k);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	select(0, n - 1, m);
	if (result < k) {
		cout << -1;
	}
	else {
		cout << a << ' ' << b;
	}
	return 0;
}