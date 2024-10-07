#include <bits/stdc++.h>
using namespace std;
bool visited[100001];
bool visitedgraph[1000001];
int n = 0, m = 0;
int result = 0;
int parent[100001];
void merge(int a, int b) {
	parent[a] = b;
}
vector<int>v;
void dfs(int x) {
	if (x == n) {
		v.push_back(n);
		return;
	}
	v.push_back(x);
	dfs(parent[x]);
}
void bfs() {
	visited[n] = true;
	queue<pair<int, int>>q;
	q.push({n, 0});
	for (int i = 0; i <= 100000; i++) {
		parent[i] = i;
	}
	while (!q.empty()) {
		int temp = q.front().first;
		int time = q.front().second;
		if (temp == m) {
			result = time;
			dfs(m);
			reverse(v.begin(), v.end());
			cout << result << '\n';
			for (auto& i : v) {
				cout << i << ' ';
			}
			return;
		} 
		visited[temp] = true;
		q.pop();
		if (temp + 1 <= 100000 && !visited[temp + 1]) {
			q.push({ temp + 1, time + 1 });
			merge(temp + 1, temp);
			visited[temp + 1] = true;
		}
		if (temp - 1 >= 0 && !visited[temp - 1]) {
			q.push({ temp - 1, time + 1 });
			merge(temp - 1, temp);
			visited[temp - 1] = true;
		}
		if (temp * 2 <= 100000 && !visited[temp * 2]) {
			q.push({ temp * 2, time + 1 });
			merge(temp * 2, temp);
			visited[temp * 2] = true;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bfs();
	return 0;
}