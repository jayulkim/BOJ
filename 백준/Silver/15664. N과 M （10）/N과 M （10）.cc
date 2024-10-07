#include <bits/stdc++.h>
using namespace std;
vector<int>graph;
int n = 0, m = 0;
bool visited[9];
vector<int>v;
int idx = -1;
void dfs() {
	if (graph.size() == m) {
		for (auto& i : graph) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	int temp = 0;
	for (int i = idx + 1; i < v.size(); i++) {
		if (!visited[i] && v[i] != temp) {
			graph.push_back(v[i]);
			visited[i] = true;
			idx = i;
			dfs();
			visited[i] = false;
			temp = v[i];
			graph.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	dfs();
	return 0;
}