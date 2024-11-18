#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[100001];
vector<bool>dp(100001, false);
vector<bool>visited(100001, false);
vector<ll>result;
bool dfs(ll parent, ll start) {
	for (auto& i : graph[start]) {
		if (i != parent) {
			dp[start] = dp[start] | dfs(start, i);
		}
	}
	return dp[start];
}
string temp = "";
void solve(ll start) {
	if (!dp[start]) {
		return;
	}
	visited[start] = true;
	result.push_back(start);
	for (auto& i : graph[start]) {
		if (!visited[i]) {
			solve(i);
		}
		result.push_back(start);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll num = 0;
		cin >> num;
		dp[num] = true;
	}
	for (int i = 0; i < n - 1; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	dfs(-1, 0);
	solve(0);
	result.erase(unique(result.begin(), result.end()), result.end());
	cout << result.size() - 1 << '\n';
	for (auto& i : result) {
		cout << i << ' ';
	}
	return 0;
}