#include <bits/stdc++.h>
using namespace std;
int parent[201];
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
	}
	else {
		parent[b] = a;
	}
}
int Map[201][201];
int main(void) {
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> Map[i][j];
		}
	}
	vector<int>v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (Map[i][j] == 1 && parent[i] != parent[j]) {
				merge(i, j);
			}
		}
	}
	for (int i = 0; i < m - 1; i++) {
		if (parent[v[i]] != parent[v[i + 1]]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}