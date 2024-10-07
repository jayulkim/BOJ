#include <bits/stdc++.h>
using namespace std;
vector<int>graph[500001];
bool visited[500001];
int turn = 0;
void bfs(int start) {
	visited[start] = true;
	queue<pair<int, int>>q;
	q.push({ start, 0 });
	while (!q.empty()) {
		pair<int, int>temp = q.front();
		q.pop();
		visited[temp.first] = true;
		if (!graph[temp.first].empty()) {
			int count = 0;
			for (auto& i : graph[temp.first]) {
				if (!visited[i]) {
					count++;
					q.push({ i, temp.second + 1 });
					visited[i] = true;
				}
			}
			if (count == 0) {
				turn += temp.second;
			}
		}
		else {
			turn += temp.second;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	bfs(1);
	if (turn % 2 == 0) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
	return 0;
}