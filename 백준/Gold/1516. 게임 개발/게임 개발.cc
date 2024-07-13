#include <bits/stdc++.h>
using namespace std;
int n = 0;
int degree[501];
int weight[501];
int result[501];
vector<int>graph[501];
void toposort() {
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) {
			result[i] = weight[i];
			q.push(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (!q.empty()) {
			int temp = q.front();
			q.pop();
			for (auto& j : graph[temp]) {
				result[j] = max(result[j], result[temp] + weight[j]);
				if (--degree[j] == 0) {
					q.push(j);
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
		while (1) {
			int num = 0;
			cin >> num;
			if (num == -1) {
				break;

			}
			graph[num].push_back(i);
			degree[i]++;
		}
	}
	toposort();
	for (int i = 1; i <= n; i++) {
		cout << result[i] << '\n';
	}
	return 0;
}