#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<vector<ll>>dp(500001, vector<ll>(3, -1));
vector<vector<ll>>v(500001, vector<ll>(3, -1));
vector<ll>graph[500001];
vector<char>ary = { 'R', 'G', 'B' };
string result(500001, '\0');
ll n = 0;
ll dfs(ll parent, ll node, ll rgb) {
	if (dp[node][rgb] != -1) {
		return dp[node][rgb];
	}
	ll weight = v[node][rgb];
	if (rgb == 0) {
		for (auto& i : graph[node]) {
			if (parent != i) {
				weight += max(dfs(node, i, 1), dfs(node, i, 2));
			}
		}
	}
	if (rgb == 1) {
		for (auto& i : graph[node]) {
			if (parent != i) {
				weight += max(dfs(node, i, 0), dfs(node, i, 2));
			}
		}
	}
	if (rgb == 2) {
		for (auto& i : graph[node]) {
			if (parent != i) {
				weight += max(dfs(node, i, 0), dfs(node, i, 1));
			}
		}
	}
	return dp[node][rgb] = weight;
}
void getcolor(ll parentcolor, ll parent, ll node) {
	ll Max = 0;
	ll idx = 0;
	for (int i = 0; i < 3; i++) {
		if (parentcolor != i && dp[node][i] > Max) {
			Max = dp[node][i];
			idx = i;
		}
	}
	result[node] = ary[idx];
	for (auto& i : graph[node]) {
		if (parent != i) {
			getcolor(idx, node, i);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[i][j];
		}
	}
	cout << max({ dfs(-1, 1, 0), dfs(-1, 1, 1), dfs(-1, 1, 2) }) << '\n';
	getcolor(-1, -1, 1);
	for (int i = 1; i <= n; i++) {
		cout << result[i];
	}
	return 0;
}