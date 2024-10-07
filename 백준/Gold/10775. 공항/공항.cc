#include <bits/stdc++.h>
using namespace std;
int parent[100001];
void init(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}
int getparent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getparent(parent[x]);
}
void merge(int a, int b) {
	a = getparent(a);
	b = getparent(b);
	if (a > b) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	init(n);
	int count = 0;
	for (int i = 0; i < m; i++) {
		int num = 0;
		cin >> num;
		if (getparent(num) != 0) {
			count++;
		}
		else {
			break;
		}
		merge(getparent(num), getparent(num) - 1);
	}
	cout << count;
	return 0;
}