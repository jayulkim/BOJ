#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[100001];
ll dp[100001];
ll dfs(ll start) {
	dp[start] = 1;
	for (auto& i : graph[start]) {
		if (!dp[i]) {
			dp[start] += dfs(i);
		}
	}
	return dp[start];
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
	vector<ll>weight;
	for (int i = 0; i < n - 1; i++) {
		ll num = 0;
		cin >> num;
		weight.push_back(num);
	}
	sort(weight.begin(), weight.end());
	dfs(1);
	vector<ll>cost;
	for (int i = 2; i <= n; i++) {
		cost.push_back(dp[i] * (n - dp[i]));
	}
	sort(cost.begin(), cost.end(), greater<ll>());
	ll result = 0;
	for (int i = 0; i < n - 1; i++) {
		result += ((cost[i] % 1000000007) * (weight[i] % 1000000007)) % 1000000007;
		result %= 1000000007;
	}
	cout << result % 1000000007;
	return 0;
}