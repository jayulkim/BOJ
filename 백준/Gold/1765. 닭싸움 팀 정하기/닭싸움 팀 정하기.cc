#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
ll parent[1001];
vector<ll>graph[1001];
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
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		char c;
		ll a = 0, b = 0;
		cin >> c >> a >> b;
		if (c == 'F') {
			merge(a, b);
		}
		else {
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (graph[i].size() > 1) {
			ll temp = graph[i][0];
			for (int j = 1; j < graph[i].size(); j++) {
				merge(temp, graph[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = getparent(i);
	}
	ll count = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i] == i) {
			count++;
		}
	}
	cout << count;
	return 0;
}