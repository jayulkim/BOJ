#include <bits/stdc++.h>
using namespace std;
int parent[10001];
set<int>s;
void getParent(int x) {
	s.insert(x);
	if (x == parent[x]) {
		return;
	}
	getParent(parent[x]);
}
void merge(int a, int b) {
	parent[a] = b;
}
vector<int>graph[10001];
void minParent(int x) {
	if (s.find(x) != s.end()) {
		cout << x << '\n';
		set<int>().swap(s);
		return;
	}
	minParent(parent[x]);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		int n = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < n - 1; i++) {
			int start = 0, end = 0;
			cin >> start >> end;
			merge(end, start);
		}
		int start = 0, end = 0;
		cin >> start >> end;
		getParent(start);
		minParent(end);
		for (int i = 1; i <= n; i++) {
			vector<int>().swap(graph[i]);
		}
	}
	return 0;
}