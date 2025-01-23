#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
vector<ll>graph[30001];
bool visited[30001];
vector<pll>List;
vector<ll>vv;
ll dp[30001][3001];
void bfs(ll start) {
	vector<ll>v;
	queue<ll>q;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		ll temp = q.front();
		q.pop();
		v.push_back(temp);
		visited[temp] = true;
		for (auto& i : graph[temp]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
	ll sum = 0;
	for (auto& i : v) {
		sum += vv[i];
	}
	List.push_back({ sum, v.size() });
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		vv.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			bfs(i);
		}
	}
	for (int i = 1; i <= List.size(); i++) {
		for (int j = 1; j <= k - 1; j++) {
			if (j >= List[i - 1].second) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - List[i - 1].second] + List[i - 1].first);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[List.size()][k - 1];
	return 0;
}