#include <bits/stdc++.h>
using namespace std;
int parent[51];
void init(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}
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
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	int k = 0;
	cin >> n >> m;
	vector<int>Map[51];
	init(n);
	cin >> k;
	for (int i = 0; i < k; i++) {
		int num = 0;
		cin >> num;
		parent[num] = 0;
	}
	for (int i = 0; i < m; i++) {
		int k = 0;
		cin >> k;
		int prev = 0;
		for (int j = 0; j < k; j++) {
			int num = 0;
			cin >> num;
			Map[i].push_back(num);
			if (j >= 1) {
				prev = Map[i][j - 1];
				merge(prev, num);
			}
		}
	}
	int count = m;
	for (int i = 0; i < m; i++) {
		for (auto& i : Map[i]) {
			if (getParent(i) == 0) {
				count--;
				break;
			}
		}
	}
	cout << count;
	return 0;
}