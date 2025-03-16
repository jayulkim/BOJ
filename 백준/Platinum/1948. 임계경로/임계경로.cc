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
vector<ll>dist(10001, -1e18);
vector<pll>graph[10001];
map<ll, ll>parent[10001];
ll result = 0;
ll distdegree[10001];
ll reversedegree[10001];
map<pll, ll>Map;
void disttoposort(ll start) {
	queue<ll>q;
	q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		ll temp = q.front();
		q.pop();
		for (auto& i : graph[temp]) {
			if (dist[i.second] < dist[temp] + i.first) {
				dist[i.second] = dist[temp] + i.first;
				map<ll, ll>().swap(parent[i.second]);
				parent[i.second][temp]++;
			}
			else if (dist[i.second] == dist[temp] + i.first && !parent[i.second][temp]) {
				parent[i.second][temp]++;
			}
			if (--distdegree[i.second] == 0) {
				q.push(i.second);
			}
		}
	}
}
void bfs(ll start) {
	queue<ll>q;
	q.push(start);
	while (!q.empty()) {
		ll temp = q.front();
		q.pop();
		for (auto& i : parent[temp]) {
			if (!Map[{temp, i.first}]) {
				Map[{temp, i.first}]++;
				reversedegree[i.first]++;
				q.push(i.first);
			}
		}
	}
}
void reversetoposort(ll end) {
	queue<ll>q;
	q.push(end);
	while (!q.empty()) {
		ll temp = q.front();
		q.pop();
		for (auto& i : parent[temp]) {
			result++;
			if (--reversedegree[i.first] == 0) {
				q.push(i.first);
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back({ c, b });
		distdegree[b]++;
	}
	ll start = 0, end = 0;
	cin >> start >> end;
	disttoposort(start);
	cout << dist[end] << '\n';
	bfs(end);
	reversetoposort(end);
	cout << result;
	return 0;
}