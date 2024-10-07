#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0;
vector<int>v;
bool visited[201];
bool Map[201][201];
int temp = 0;
int result = 0;
void dfs() {
	if (v.size() == 3) {
		for (int i = 0; i < v.size(); i++) {
			for (int j = i; j < v.size(); j++) {
				if (Map[v[i]][v[j]]) {
					return;
				}
			}
		}
		result++;
		return;
	}
	for (int i = temp + 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			temp = i;
			dfs();
			visited[i] = false;
			v.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		Map[start][end] = true;
		Map[end][start] = true;
	}
	dfs();
	cout << result;
	return 0;
}