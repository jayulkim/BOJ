#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
ll visited[200001];
ll parent[200001];
ll getparent(ll x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getparent(parent[x]);
}
void merge(ll a, ll b) {
	a = getparent(a);
	b = getparent(b);
	if (visited[a] > visited[b]) {
		visited[a] += visited[b];
		parent[b] = a;
	}
	else {
		visited[b] += visited[a];
		parent[a] = b;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		ll num = 0;
		cin >> num;
		if (!num) {
			visited[i] = -1;
		}
		else {
			visited[i] = 1;
		}
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		if (getparent(a) != getparent(b)) {
			merge(a, b);
		}
	}
	for (int i = 0; i < k; i++) {
		ll num = 0;
		cin >> num;
		if (visited[getparent(num)] > 0) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	return 0;
}