#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0;
vector<ll>ary(4);
struct info {
	ll start;
	ll end;
	ll weight;
	ll kind;
	bool operator()(const info& a, const info& b) {
		if (a.weight == b.weight) {
			return ary[a.kind] > ary[b.kind];
		}
		return a.weight > b.weight;
	}
};
vector<pll>v(4, { 0, 0 });
priority_queue<info, vector<info>, info>pq;
ll parent[10001];
ll getparent(ll x) {
	if (x == parent[x]) {
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
	while (count < n - 1) {
		info temp = pq.top();
		pq.pop();
		if (getparent(temp.start) != getparent(temp.end)) {
			merge(temp.start, temp.end);
			count++;
			result += temp.weight;
			v[temp.kind].first++;
			v[temp.kind].second += temp.weight;
		}
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	ary[3] = 3;
	for (int i = 0; i < 3; i++) {
		ll num = 0;
		cin >> num;
		ary[num] = i;
	}
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0, weight = 0, kind = 0;
		cin >> start >> end >> weight >> kind;
		pq.push({ start, end, weight, kind });
	}
	cout << kruskal(n) << '\n';
	for (int i = 0; i < 3; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}