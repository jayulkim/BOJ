#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
vector<int>graph[32001];
int degree[32001];
void toposort(int n) {
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!q.empty()) {
			int temp = q.front();
			q.pop();
			cout << temp << ' ';
			for (auto& i : graph[temp]) {
				if (--degree[i] == 0) {
					q.push(i);
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		degree[end]++;
	}
	toposort(n);
	return 0;
}