// 기존 방법 : a, b구분안하고 한 집합으로 묶음
// --> a의 1과 b의 2와 a의 3이 한 집합일 때 1은 1끼리만 2는 2끼리만 3은 3끼리만 바꿔야된다? x
// a랑 b구분해서 묶고 a의 것과 b의 것끼리만 바꿔야된다 o
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
vector<ll>graph[401];
vector<pll>v;
ll parent[401];
bool visited[401];
vector<pll>result;
bool visitedvisited[101][101];
ll getparent(ll x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = getparent(parent[x]);
}
void merge(ll a, ll b) {
	a = getparent(a);
	b = getparent(b);
	if (a > b) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}
void bfs(ll start) {
	visited[start] = true;
	queue<ll>q;
	q.push(start);
	while (!q.empty()) {
		ll temp = q.front();
		q.pop();
		merge(start, temp);
		visited[temp] = true;
		for (auto& i : graph[temp]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= 2 * n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b + n);
		graph[b + n].push_back(a);
	}
	for (int i = 1; i <= 2 * n; i++) {
		if (!visited[i]) {
			bfs(i);
			ll a = 0, b = 0;
			for (int j = 1; j <= n; j++) {
				parent[j] = getparent(j);
				if (parent[j] == i) {
					a++;
				}
			}
			for (int j = n + 1; j <= 2 * n; j++) {
				parent[j] = getparent(j);
				if (parent[j] == i) {
					b++;
				}
			}
			v.push_back({ a, b });
		}
	}
	result.push_back({ 0, 0 });
	for (auto& i : v) {
		ll temp = result.size();
		for (int j = 0; j < temp; j++) {
			if (result[j].first + i.first <= n / 2 && result[j].second + i.second <= n / 2 && !visitedvisited[result[j].first + i.first][result[j].second + i.second]) {
				result.push_back({ result[j].first + i.first, result[j].second + i.second });
				visitedvisited[result[j].first + i.first][result[j].second + i.second] = true;
			}
		}
	}
	ll Max = 0;
	for (auto& i : result) {
		if (i.first == i.second) {
			Max = max(Max, i.second);
		}
	}
	cout << Max;
	return 0;
}