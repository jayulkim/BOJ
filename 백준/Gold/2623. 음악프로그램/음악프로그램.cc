#include <bits/stdc++.h>
using namespace std;
vector<int>graph[1001];
int degree[1001];
int stop = 0;
vector<int>result;
void toposort(int n) {
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (!q.empty()) {
			int temp = q.front();
			q.pop();
			result.push_back(temp);
			for (auto& j : graph[temp]) {
				if (--degree[j] == 0) {
					q.push(j);
				}
			}
		}
		else {
			cout << 0;
			stop++;
			return;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k = 0;
		cin >> k;
		int prev = 0;
		for (int j = 0; j < k; j++) {
			int num = 0;
			cin >> num;
			if (j == 0) {
				prev = num;
			}
			else {
				graph[prev].push_back(num);
				degree[num]++;
				prev = num;
			}
		}
	}
	toposort(n);
	if (stop == 0) {
		for (auto& i : result) {
			cout << i << ' ';
		}
	}
	return 0;
}