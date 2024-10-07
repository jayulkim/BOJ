#include <bits/stdc++.h>
using namespace std;
struct info {
	int start;
	int end;
	double weight;
};
struct cmp {
	bool operator()(const info& a, const info& b) {
		return a.weight > b.weight;
	}
};
int parent[1001];
void init(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}
double getdistence(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
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
priority_queue<info, vector<info>, cmp>pq;
double result = 0;
void kruskal(int n) {
	int count = 0;
	while (count < n - 1) {
		info temp = pq.top();
		pq.pop();
		if (getparent(temp.start) != getparent(temp.end)) {
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
	init(n);
	vector<pair<int, int>>v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			pq.push({ i, j, getdistence(v[i].first, v[i].second, v[j].first, v[j].second) });
		}
	}
	for (int i = 0; i < m; i++) {
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		if (getparent(num1) != getparent(num2)) {
			merge(num1, num2);
			n--;
		}
	}
	kruskal(n);
	cout.precision(2);
	cout << fixed;
	cout << result;
	return 0;
}