#include <bits/stdc++.h>
using namespace std;
int parent[1000001];
int visited[1000001];
int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]);
}
void merge(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) {
		parent[a] = b;
		visited[b] += visited[a];
		visited[a] = 0;
	}
	else {
		parent[b] = a;
		visited[a] += visited[b];
		visited[b] = 0;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 1000000; i++) {
		parent[i] = i;
		visited[i] = 1;
	}
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char command;
		int a = 0, b = 0;
		cin >> command;
		if (command == 'I') {
			cin >> a >> b;
			if (getParent(a) != getParent(b)) {
				merge(a, b);
			}
		}
		else {
			cin >> a;
			cout << visited[getParent(a)] << '\n';
		}
	}
	return 0;
}