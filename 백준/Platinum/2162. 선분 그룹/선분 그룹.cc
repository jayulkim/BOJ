#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
pld vec(ld x1, ld y1, ld x2, ld y2) {
	return { x2 - x1, y2 - y1 };
}
ld ccw(pld p1, pld p2, pld p3) {
	pld a = vec(p1.first, p1.second, p2.first, p2.second);
	pld b = vec(p2.first, p2.second, p3.first, p3.second);
	ld temp = a.first * b.second - a.second * b.first;
	if (temp < 0) {
		return -1;
	}
	else if (temp > 0) {
		return 1;
	}
	else {
		return 0;
	}
}
bool cross(pld start1, pld end1, pld start2, pld end2) {
	if (start1 > end1) {
		swap(start1, end1);
	}
	if (start2 > end2) {
		swap(start2, end2);
	}
	ld a = ccw(start1, end1, start2);
	ld b = ccw(start1, end1, end2);
	ld c = ccw(start2, end2, start1);
	ld d = ccw(start2, end2, end1);
	if (a * b == 0 && c * d == 0) {
		return start1 <= end2 && start2 <= end1;
	}
	return a * b <= 0 && c * d <= 0;
}
ll parent[3001];
ll getparent(ll x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getparent(parent[x]);
}
void merge(ll a, ll b) {
	a = getparent(a);
	b = getparent(b);
	if (a > b) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}
ll visited[3001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	vector<pair<pld, pld>>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (getparent(i) != getparent(j)) {
				if (cross(v[i].first, v[i].second, v[j].first, v[j].second)) {
					merge(i, j);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		parent[i] = getparent(i);
	}
	for (int i = 0; i < n; i++) {
		visited[parent[i]]++;
	}
	ll count = 0, Max = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			count++;
			Max = max(Max, visited[i]);
		}
	}
	cout << count << '\n' << Max;
	return 0;
}