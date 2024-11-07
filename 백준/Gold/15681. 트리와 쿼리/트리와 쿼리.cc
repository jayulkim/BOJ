#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[100001];
vector<ll>dp(100001, -1);
bool visited[100001];
ll dfs(ll node) {
	if (visited[node]) {
		return 0;
	}
	if (dp[node] != -1) {
		return dp[node];
	}
	visited[node] = true;
	ll count = 1;
	for (auto& i : graph[node]) {
		count += dfs(i);
	}
	return dp[node] = count;
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
	dfs(m);
	for (int i = 0; i < k; i++) {
		ll num = 0;
		cin >> num;
		cout << dp[num] << '\n';
	}
	return 0;
}