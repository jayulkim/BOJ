#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
class Unionfind {
private:
	using ll = long long;
	using lll = tuple<ll, ll, ll>;
	ll n;
	vector<ll>parent;
	vector<ll>rank;
public:
	Unionfind(ll n) {
		this->n = n;
		parent.resize(n + 1);
		iota(parent.begin(), parent.end(), 0);
		rank.assign(n + 1, 1);
	}
	ll getparent(ll x) {
		if (x == parent[x]) {
			return x;
		}
		return parent[x] = getparent(parent[x]);
	}
	void merge(ll a, ll b) {
		a = getparent(a);
		b = getparent(b);
		if (a == b) {
			return;
		}
		if (rank[a] > rank[b]) {
			rank[a] += rank[b];
			rank[b] = 0;
			parent[b] = a;
		}
		else {
			rank[b] += rank[a];
			rank[a] = 0;
			parent[a] = b;
		}
	}
	ll minkruskal(priority_queue<lll, vector<lll>, greater<lll>>&pq) {
		ll result = 0;
		ll count = 0;
		while (!pq.empty() && count < n - 1) {
			auto [a, b, c] = pq.top();
			pq.pop();
			if (getparent(b) != getparent(c)) {
				count++;
				result += a;
				merge(b, c);
			}
		}
		return (count == n - 1 ? result : LLONG_MAX);
	}
	ll maxkruskal(priority_queue<lll>&pq) {
		ll result = 0;
		ll count = 0;
		while (!pq.empty() && count < n - 1) {
			auto [a, b, c] = pq.top();
			pq.pop();
			if (getparent(b) != getparent(c)) {
				count++;
				result += a;
				merge(b, c);
			}
		}
		return (count == n - 1 ? result : LLONG_MAX);
	}
};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<vector<ll>>graph(n + 1);
	priority_queue<lll, vector<lll>, greater<lll>>pq;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		pq.push({ c, a, b });
	}
	Unionfind u(n);
	cout << u.minkruskal(pq);
	return 0;
}