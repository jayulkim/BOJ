#include <bits/stdc++.h>
using namespace std;
vector<int>graph[32001];
priority_queue<int, vector<int>, greater<int>>pq;
int degree[32001];
int n = 0, m = 0;
void toposort() {
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) {
			pq.push(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (!pq.empty()) {
			int temp = pq.top();
			pq.pop();
			cout << temp << ' ';
			for (auto& i : graph[temp]) {
				if (--degree[i] == 0) {
					pq.push(i);
				}
			}
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
		graph[start].push_back(end);
		degree[end]++;
	}
	toposort();
	return 0;
}