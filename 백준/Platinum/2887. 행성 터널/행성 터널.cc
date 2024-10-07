#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n = 0;
struct info {
	int num = 0;
	ll x;
	ll y;
	ll z;
};
bool comparex(const info& a, const info& b) {
	return a.x < b.x;
}
bool comparey(const info& a, const info& b) {
	return a.y < b.y;
}
bool comparez(const info& a, const info& b) {
	return a.z < b.z;
}
int parent[100001];
int getParent(int x) {
	if (x == parent[x]) {
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
ll getDistencex(ll x1, ll x2) {
	return abs(x1 - x2);
}
ll getDistencey(ll y1, ll y2) {
	return abs(y1 - y2);
}
ll getDistencez(ll z1, ll z2) {
	return abs(z1 - z2);
}
struct road {
	int start;
	int end;
	ll weight;
	bool operator()(const road& a, const road& b) {
		return a.weight > b.weight;
	}
};
priority_queue<road, vector<road>, road>pq;
ll kruskal() {
	ll result = 0, count = 0;
	while (!pq.empty() && count < n - 1) {
		road temp = pq.top();
		pq.pop();
		if (getParent(temp.start) != getParent(temp.end)) {
			merge(temp.start, temp.end);
			result += temp.weight;
			count++;
		}
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	vector<info>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y >> v[i].z;
		v[i].num = i;
	}
	sort(v.begin(), v.end(), comparex);
	for (int i = 0; i < n - 1; i++) {
		pq.push({ v[i].num, v[i + 1].num, getDistencex(v[i].x, v[i + 1].x)});
	}
	sort(v.begin(), v.end(), comparey);
	for (int i = 0; i < n - 1; i++) {
		pq.push({ v[i].num, v[i + 1].num, getDistencey(v[i].y, v[i + 1].y) });
	}
	sort(v.begin(), v.end(), comparez);
	for (int i = 0; i < n - 1; i++) {
		pq.push({ v[i].num, v[i + 1].num, getDistencez(v[i].z, v[i + 1].z) });
	}
	cout << kruskal();
	return 0;
}