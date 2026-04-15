#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>>minpq;
priority_queue<tuple<ll, ll, ll>>maxpq;
ll parent[1001];
ll getparent(ll x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = getparent(parent[x]);
}
void merge(ll a, ll b) {
	a = getparent(a);
	b = getparent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}
ll minkruskal() {
	ll result = 0;
	ll count = 0;
	while (count < n) {
		auto [a, b, c] = minpq.top();
		minpq.pop();
		if (getparent(b) != getparent(c)) {
			merge(b, c);
			result += a;
			count++;
		}
	}
	return result * result;
}
ll maxkruskal() {
	ll result = 0;
	ll count = 0;
	while (count < n) {
		auto [a, b, c] = maxpq.top();
		maxpq.pop();
		if (getparent(b) != getparent(c)) {
			merge(b, c);
			result += a;
			count++;
		}
	}
	return result * result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m + 1; i++) {
		ll start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		if (!weight) {
			minpq.push({ 1, start, end });
			maxpq.push({ 1, start, end });
		}
		else {
			minpq.push({ 0, start, end });
			maxpq.push({ 0, start, end });
		}
	}
	ll Max = maxkruskal();
	parent[0] = 0;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	ll Min = minkruskal();
	cout << Max - Min;
	return 0;
}