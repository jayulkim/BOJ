#include <bits/stdc++.h>
using namespace std;
int parent[50001];
bool visited[50001];
string str = "";
string temp = "";
void getParent(int x) {
	str[x] = '1';
	if (x == 1) {
		return;
	}
	getParent(parent[x]);
}
void merge(int a, int b) {
	parent[a] = b;
}
vector<int>graph[50001];
void bfs(int start) {
	visited[start] = true;
	queue<int>q;
	q.push(start);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		visited[temp] = true;
		for (auto& i : graph[temp]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
				merge(i, temp);
			}
		}
	}
}
void minParent(int x) {
	if (str[x] == '1') {
		cout << x << '\n';
		str = temp;
		return;
	}
	minParent(parent[x]);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		str += '0';
	}
	str += '0';
	temp = str;
	for (int i = 0; i < n - 1; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	bfs(1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		getParent(start);
		minParent(end);
	}
	return 0;
}