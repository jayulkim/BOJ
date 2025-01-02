#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll degree[200001];
vector<ll>graph[200001];
bool visited[200001];
vector<ll>depth[200001];
void toposort() {
	queue<pll>q;
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) {
			q.push({ i, 1 });
		}
	}
	while (q.size() > 1 && !q.empty()) {
		pll temp = q.front();
		q.pop();
		visited[temp.first] = true;
		for (auto& i : graph[temp.first]) {
			if (!visited[i]) {
				depth[i].push_back(temp.second);
				if (--degree[i] == 0) {
					q.push({ i, temp.second + 1 });
				}
			}
		}
	}
	bool find = false;
	for (int i = 1; i <= n; i++) {
		if (depth[i].size() > 0) {
			ll temp = depth[i][0];
			for (int j = 1; j < depth[i].size(); j++) {
				if (temp != depth[i][j]) {
					find = true;
					cout << -1;
					return;
				}
			}
		}
	}
	cout << 1 << '\n';
	cout << q.front().first;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		degree[a]++;
		degree[b]++;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (degree[i] != 1 && degree[i] != 3) {
			cout << -1;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		degree[i]--;
	}
	toposort();
	return 0;
}