#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
vector<ll>graph[20001];
bool visited[20001];
ll parent[20001];
void bfs(ll start) {
	visited[start] = true;
	queue<pll>q;
	q.push({ start, 0 });
	while (!q.empty()) {
		pll temp = q.front();
		q.pop();
		visited[temp.first] = true;
		parent[temp.first] = temp.second;
		for (auto& i : graph[temp.first]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push({ i, (temp.second + 1) % 2 });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			ll start = 0, end = 0;
			cin >> start >> end;
			graph[start].push_back(end);
			graph[end].push_back(start);
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				bfs(i);
			}
		}
		bool find = false;
		for (int i = 1; i <= n; i++) {
			if (find) {
				break;
			}
			for (auto& j : graph[i]) {
				if (parent[j] == parent[i]) {
					find = true;
					cout << "NO" << '\n';
					break;
				}
			}
		}
		if (!find) {
			cout << "YES" << '\n';
		}
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			vector<ll>().swap(graph[i]);
		}
		memset(parent, 0, sizeof(parent));
	}
	return 0;
}