#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[1001];
bool visited[1001];
void bfs(ll start) {
	visited[start] = true;
	queue<ll>q;
	q.push(start);
	while (!q.empty()) {
		ll temp = q.front();
		q.pop();
		visited[temp] = true;
		for (auto& i : graph[temp]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
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
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> m;
			graph[i].push_back(m);
		}
		ll result = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				bfs(i);
				result++;
			}
		}
		cout << result << '\n';
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			vector<ll>().swap(graph[i]);
		}
	}
	return 0;
}