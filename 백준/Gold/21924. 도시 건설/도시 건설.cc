#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll> lll;
typedef tuple<pll, string, ll> pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll sum = 0;
	priority_queue<lll, vector<lll>, greater<lll>>pq;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		sum += c;
		pq.push({ c, a, b });
	}
	vector<ll>parent(n + 1);
	iota(parent.begin(), parent.end(), 0);
	vector<ll>rank(n + 1, 0);
	function<ll(ll)> getparent = [&](ll x) -> ll {
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = getparent(parent[x]);
		};
	function<void(ll, ll)> merge = [&](ll a, ll b) -> void {
		a = getparent(a);
		b = getparent(b);
		if (rank[a] < rank[b]) {
			parent[a] = b;
		}
		else {
			parent[b] = a;
			if (rank[a] == rank[b]) {
				rank[a]++;
			}
		}
		};
	ll count = 0;
	ll result = 0;
	while (!pq.empty() && count < n - 1) {
		auto [a, b, c] = pq.top();
		pq.pop();
		if (getparent(b) != getparent(c)) {
			merge(b, c);
			result += a;
			count++;
		}
	}
	if (count != n - 1) {
		cout << -1;
		return 0;
	}
	cout << sum - result;
	return 0;
}