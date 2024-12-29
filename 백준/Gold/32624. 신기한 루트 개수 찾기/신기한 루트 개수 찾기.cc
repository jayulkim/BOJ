#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool a[300001];
bool b[300001];
vector<ll>graph[300001];
void dfs1(ll start, ll end) {
	a[start] = true;
	for (auto& i : graph[start]) {
		if (i != end && !a[i]) {
			dfs1(i, end);
		}
	}
}
void dfs2(ll start, ll end) {
	b[start] = true;
	for (auto& i : graph[start]) {
		if (i != end && !b[i]) {
			dfs2(i, end);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n - 1; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs1(m, k);
	dfs2(k, m);
	ll count = 0;
	for (int i = 1; i <= n; i++) {
		if (i != m && i != k && a[i] && b[i]) {
			count++;
		}
	}
	cout << count;
	return 0;
}