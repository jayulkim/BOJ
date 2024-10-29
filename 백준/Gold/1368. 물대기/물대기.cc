#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;
ll parent[301];
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
priority_queue<tp, vector<tp>, greater<tp>>pq;
ll kruskal(ll n) {
	ll count = 0;
	ll result = 0;
	while (count < n - 1) {
		auto [a, b, c] = pq.top();
		pq.pop();
		if (getparent(b) != getparent(c)) {
			count++;
			result += a;
			merge(b, c);
		}
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		ll num = 0;
		cin >> num;
		pq.push({ num, 0, i });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ll num = 0;
			cin >> num;
			if (i < j) {
				pq.push({ num, i, j });
			}
		}
	}
	cout << kruskal(n + 1);
	return 0; 
}