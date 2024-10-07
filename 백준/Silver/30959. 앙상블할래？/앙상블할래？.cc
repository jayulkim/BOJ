#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0, Max = 0;
vector<int>Map;
vector<int>student[17];
vector<int>graph;
bool visited[17];
int temp = -1;
bool Find = false;
int getScore(int n) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		if (student[n][i] == Map[i]) {
			count++;
		}
	}
	return count;
}
vector<int> merge(int n) {
	vector<int>result;
	if (n == 1) {
		return student[graph[0]];
	}
	vector<pair<int, int>>v(m);
	for (int i = 0; i < m; i++) {
		v[i].first = 0;
		v[i].second = 0;
	}
	for (auto& i : graph) {
		for (int j = 0; j < m; j++) {
			if (!student[i][j]) {
				v[j].first++;
			}
			else {
				v[j].second++;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (v[i].first > v[i].second) {
			result.push_back(0);
		}
		else {
			result.push_back(1);
		}
	}
	return result;
}
void dfs(int size) {
	if (Find) {
		return;
	}
	if (graph.size() == size) {
		vector<int>result = merge(graph.size());
		int count = 0;
		for (int i = 0; i < m; i++) {
			if (Map[i] == result[i]) {
				count++;
			}
		}
		if (count > Max) {
			cout << 1;
			Find = true;
		}
		return;
	}
	for (int i = temp + 1; i < n; i++) {
		if (!visited[i]) {
			graph.push_back(i);
			temp = i;
			visited[i] = true;
			dfs(size);
			graph.pop_back();
			visited[i] = false;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num = 0;
		cin >> num;
		Map.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num = 0;
			cin >> num;
			student[i].push_back(num);
		}
		Max = max(Max, getScore(i));
	}
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1 && !Find) {
			dfs(i);
			temp = -1;
		}
	}
	if (!Find) {
		cout << 0;
	}
	return 0;
}