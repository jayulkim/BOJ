#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[100001];
ll id = 0;
ll visited[100001];
bool finished[100001];
vector<ll>s;
map<ll, ll>Map;
ll Mapid = 0;
bool visitedid[100001];
bool degree[100001];
ll dfs(ll start) {
	visited[start] = ++id;
	s.push_back(start);
	ll parent = visited[start];
	for (auto& i : graph[start]) {
		if (!visited[i]) {
			parent = min(parent, dfs(i));
		}
		else if (!finished[i]) {
			parent = min(parent, visited[i]);
		}
	}
	if (parent == visited[start]) {
		Mapid++;
		while (1) {
			ll temp = s.back();
			s.pop_back();
			Map[temp] = Mapid;
			finished[temp] = true;
			if (temp == start) {
				break;
			}
		}
	}
	return parent;
}
void bfs(ll start) {
	visitedid[start] = true;
	queue<ll>q;
	q.push(start);
	while (!q.empty()) {
		ll temp = q.front();
		q.pop();
		visitedid[temp] = true;
		ll d = Map[temp];
		for (auto& i : graph[temp]) {
			if (d != Map[i]) {
				degree[Map[i]] = true;
			}
			if (!visitedid[i] ) {
				q.push(i);
				visitedid[i] = true;
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
			ll a = 0, b = 0;
			cin >> a >> b;
			graph[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!visitedid[i]) {
				bfs(i);
			}
		}
		ll count = 0;
		for (int i = 1; i <= Mapid; i++) {
			if (!degree[i]) {
				count++;
			}
		}
		cout << count << '\n';
		map<ll, ll>().swap(Map);
		memset(visitedid, false, sizeof(visitedid));
		memset(visited, 0, sizeof(visited));
		memset(finished, false, sizeof(finished));
		memset(degree, false, sizeof(degree));
		Mapid = 0;
		for (int i = 1; i <= n; i++) {
			vector<ll>().swap(graph[i]);
		}
		id = 0;
		vector<ll>().swap(s);
	}
	return 0;
}