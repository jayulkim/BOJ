#include <bits/stdc++.h>
using namespace std;
int parent[4000001];
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
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	init(n);
	vector<int>v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < k; i++) {
		int num = 0;
		cin >> num;
		int start = 0, end = m - 1, mid = 0;
		while (start < end) {
			mid = (start + end) / 2;
			if (getparent(v[mid]) > num) {
				end = mid;
			}
			else {
				start = mid + 1;
			}
		}
		cout << v[end] << '\n';
		merge(num, getparent(v[end]));
	}
	return 0;
}