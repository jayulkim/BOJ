#include <bits/stdc++.h>
using namespace std;
bool visited[11];
vector<int>graph;
vector<pair<int, int>>v;
vector<pair<int, int>>start;
int n = 0;
int Max = 0;
void dfs() {
	if (graph.size() == n - 2) {
		int result = 0;
		for (auto& i : graph) {
			for (int j = 1; j < v.size() - 1; j++) {
				if (v[j].first == i) {
					result += (v[j - 1].second * v[j + 1].second);
					v.erase(v.begin() + j);
					break;
				}
			}
		}
		Max = max(result, Max);
		vector<pair<int, int>>().swap(v);
		for (int i = 0; i < start.size(); i++) {
			v.push_back(start[i]);
		}
		return;
	}
	for (int i = 1; i < v.size() - 1; i++) {
		if (!visited[i]) {
			visited[i] = true;
			graph.push_back(v[i].first);
			dfs();
			visited[i] = false;
			graph.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		v.push_back({ i, num });
		start.push_back({ i, num });
	}
	dfs();
	cout << Max;
	return 0;
}