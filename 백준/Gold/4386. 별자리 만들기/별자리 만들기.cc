#include <bits/stdc++.h>
using namespace std;
int parent[100101];
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
int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]);
}
double getDistence(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
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
double result = 0;
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
	int n = 0;
	cin >> n;
	for (int i = 1; i <= 100100; i++) {
		parent[i] = i;
	}
	vector<pair<double, double>>v(n);
	for (int i = 0; i < n; i++) {
		double x = 0, y = 0;
		cin >> x >> y;
		v[i].first = x;
		v[i].second = y;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			pq.push({ i, j, getDistence(v[i].first, v[i].second, v[j].first, v[j].second) });
		}
	}
	kruskal(n);
	cout << result;
	return 0;
}