#include <bits/stdc++.h>
using namespace std;
char Map[51][51];
int n = 0;
vector<int>graph[51];
int degree[51];
bool Find = false;
void toposort() {
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) {
			q.push(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (!q.empty()) {
			int temp = q.front();
			q.pop();
			for (auto& j : graph[temp]) {
				if (--degree[j] == 0) {
					q.push(j);
				}
			}
		}
		else {
			Find = true;
			return;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (Map[i][j] != 'Y' && Map[j][i] == 'Y') {
				graph[j].push_back(i);
				degree[i]++;
			}
			else if (Map[i][j] == 'Y' && Map[j][i] != 'Y') {
				graph[i].push_back(j);
				degree[j]++;
			}
		}
	}
	toposort();
	if (Find) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
	return 0;
}