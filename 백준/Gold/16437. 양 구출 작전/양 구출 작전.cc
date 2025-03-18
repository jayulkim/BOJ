#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[123457];
ll sheep[123457];
ll wolf[123457];
ll result = 0;
ll parent[123467];
void dfs(ll start, ll prev) {
	if (prev != -1) {
		parent[start] = prev;
	}
	for (auto& i : graph[start]) {
		if (prev != i) {
			dfs(i, start);
		}
	}
}
ll getparent(ll x, ll temp) {
	if (x == 1) {
		result += temp;
		return 1;
	}
	if (wolf[x] >= temp) {
		wolf[x] -= temp;
		return x;
	}
	else {
		temp -= wolf[x];
		wolf[x] = 0;
		return parent[x] = getparent(parent[x], temp);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		char c;
		ll a = 0, b = 0;
		cin >> c >> a >> b;
		if (c == 'S') {
			sheep[i] = a;
		}
		else {
			wolf[i] = a;
		}
		graph[i].push_back(b);
		graph[b].push_back(i);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++) {
		if (sheep[i]) {
			getparent(i, sheep[i]);
		}
	}
	cout << result;
	return 0;
}