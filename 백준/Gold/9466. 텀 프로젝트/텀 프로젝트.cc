#include <bits/stdc++.h>
using namespace std;
int graph[100001];
bool visited[100001];
map<int, int>m;
int idx = 0;
int result = 0;
void dfs(int x) {
	if (!visited[x]) {
		visited[x] = true;
		m.insert({x, idx++});
		dfs(graph[x]);
	}
	else {
		if (m.find(x) != m.end()) {
			result += (m.size() - m.find(x)->second);
			map<int, int>().swap(m);
			idx = 0;
			return;
		}
		else {
			map<int, int>().swap(m);
			idx = 0;
			return;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		int n = 0;
		cin >> n; 
		for (int i = 1; i <= n; i++) {
			cin >> graph[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		cout << n - result << '\n';
		memset(visited, false, sizeof(visited));
		result = 0;
		idx = 0;
	}
}