#include <bits/stdc++.h>
using namespace std;
bool visited[9];
vector<int>graph;
int temp = -1;
int n = 0, m = 0;
vector<int>v;
void dfs() {
	if (graph.size() == m) {
		for (auto& i : graph) {
			cout << i << ' ';
		}
		cout << '\n';
	}
	for (int i = temp + 1; i < v.size(); i++) {
		if (!visited[i]) {
			graph.push_back(v[i]);
			visited[i] = true;
			temp = i;
			dfs();
			visited[i] = false;
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