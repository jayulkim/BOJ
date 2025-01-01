#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool visited[1001];
ll parent[1001];
priority_queue<tp, vector<tp>, greater<tp>>pq;
ll getparent(ll x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getparent(parent[x]);
}
void merge(ll a, ll b) {
	a = getparent(a);
	b = getparent(b);
	if (visited[b]) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}
ll kruskal() {
	ll result = 0, count = 0;
	while (count < n - k) {
		auto [a, b, c] = pq.top();
		pq.pop();
		if (getparent(b) != getparent(c) && !(visited[getparent(b)] && visited[getparent(c)])) {
			merge(b, c);
			result += a;
			count++;
		}
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < k; i++) {
		ll num = 0;
		cin >> num;
		visited[num] = true;
	}
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, weight = 0;
		cin >> a >> b >> weight;
		pq.push({ weight, a, b });
	}
	cout << kruskal();
	return 0;
}