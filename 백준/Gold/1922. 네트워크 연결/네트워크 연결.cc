#include <bits/stdc++.h>
using namespace std;
int parent[1001];
struct info {
	int start;
	int end;
	int weight;
};
struct cmp {
	bool operator()(const info& a, const info& b) {
		return a.weight > b.weight;
	}
};
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
priority_queue<info, vector<info>, cmp>pq;
int result = 0;
void kruskal(int n) {
	int count = 0, a = 0, b = 0;
	while (count < n - 1) {
		info temp = pq.top();
		pq.pop();
		if (getParent(temp.start) != getParent(temp.end)) {
			result += temp.weight;
			count++;
			merge(temp.start, temp.end);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		pq.push({ start, end, weight });
	}
	kruskal(n);
	cout << result;
	return 0;
}