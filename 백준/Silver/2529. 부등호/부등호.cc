#include <bits/stdc++.h>
using namespace std;
int n = 0;
vector<char>v;
vector<int>graph;
bool visited[10];
vector<vector<int>>result;
void dfs() {
	if (graph.size() == n + 1) {
		result.push_back(graph);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (!visited[i]) {
			if (graph.size() > 0 && ((v[graph.size() - 1] == '>') && graph.back() > i) || (v[graph.size() - 1] == '<' && graph.back() < i)) {
				graph.push_back(i);
				visited[i] = true;
				dfs();
				visited[i] = false;
				graph.pop_back();
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		v.push_back(c);
	}
	for (int i = 0; i <= 9; i++) {
		visited[i] = true;
		graph.push_back(i);
		dfs();
		visited[i] = false;
		graph.pop_back();
	}
	for (int i = 0; i < n + 1; i++) {
		cout << result.back()[i];
	}
	cout << '\n';
	for (int i = 0; i < n + 1; i++) {
		cout << result.front()[i];
	}
	return 0;
}