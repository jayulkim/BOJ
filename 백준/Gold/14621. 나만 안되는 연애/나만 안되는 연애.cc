#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
priority_queue<tp, vector<tp>, greater<tp>>pq;
vector<char>v(1001);
ll parent[1001];
ll getparent(ll x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getparent(parent[x]);
}
void merge(ll a, ll b) {
	a = getparent(a);
	b = getparent(b);
	if (a > b) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}
ll kruskal(ll n) {
	ll result = 0, count = 0;
	while (count < n - 1 && !pq.empty()) {
		auto [a, b, c] = pq.top();
		pq.pop();
		if (getparent(b) != getparent(c) && v[b] != v[c]) {
			count++;
			result += a;
			merge(b, c);
		}
	}
	if (count < n - 1) {
		return -1;
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		v[i] = c;
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, weight = 0;
		cin >> a >> b >> weight;
		pq.push({ weight, a, b });
	}
	cout << kruskal(n);
	return 0;
}