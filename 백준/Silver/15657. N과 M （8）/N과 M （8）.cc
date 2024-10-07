#include <bits/stdc++.h>
using namespace std;
vector<int>graph;
int n = 0, m = 0;
vector<int>v;
int temp = 0;
void dfs() {
	if (graph.size() == m) {
		for (auto& i : graph) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = temp; i < v.size(); i++) {
		graph.push_back(v[i]);
		temp = i;
		dfs();
		graph.pop_back();
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