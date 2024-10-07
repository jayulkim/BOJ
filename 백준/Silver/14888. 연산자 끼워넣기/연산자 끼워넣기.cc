#include <bits/stdc++.h>
using namespace std;
vector<int>graph;
int n = 0;
vector<int>v;
vector<int>circulator;
bool visited[12];
int Min = 1000000001;
int Max = -Min;
void dfs() {
	if (graph.size() == n - 1) {
		int temp = v[0];
		for (int i = 0; i < n - 1; i++) {
			if (graph[i] == 0) {
				temp += v[i + 1];
			}
			else if (graph[i] == 1) {
				temp -= v[i + 1];
			}
			else if (graph[i] == 2) {
				temp *= v[i + 1];
			}
			else if (graph[i] == 3) {
				temp /= v[i + 1];
			}
		}
		Max = max(Max, temp);
		Min = min(Min, temp);
		return;
	}
	for (int i = 0; i < circulator.size(); i++) {
		if (!visited[i]) {
			graph.push_back(circulator[i]);
			visited[i] = true;
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
		v.push_back(num);
	}
	for (int i = 0; i < 4; i++) {
		int num = 0;
		cin >> num;
		for (int j = 0; j < num; j++) {
			circulator.push_back(i);
		}
	}
	dfs();
	cout << Max << '\n' << Min;
	return 0;
}