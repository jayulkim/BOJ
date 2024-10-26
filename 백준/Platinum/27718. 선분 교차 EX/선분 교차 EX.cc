#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
pld vec(ld x1, ld y1, ld x2, ld y2) {
	return { x2 - x1, y2 - y1 };
}
ll ccw(pld p1, pld p2, pld p3) {
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
char cross(pld start1, pld end1, pld start2, pld end2) {
	ll a = ccw(start1, end1, start2);
	ll b = ccw(start1, end1, end2);
	ll c = ccw(start2, end2, start1);
	ll d = ccw(start2, end2, end1);
	ll e = a * b;
	ll f = c * d;
	if (e > 0 || f > 0) {
		return '0';
	}
	if (e < 0 && f < 0) {
		return '2';
	}
	if (!e && !f) {
		if (a || b || c || d) {
			return '1';
		}
		if (end1 < start1) {
			swap(start1, end1);
		}
		if (end2 < start2) {
			swap(start2, end2);
		}
		if (end1 < start2 || end2 < start1) {
			return '0';
		}
		if (end1 == start2 || start1 == end2) {
			return '1';
		}
		return '3';
	}
	return '1';
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	vector<pair<pld, pld>>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
	}
	vector<string>result;
	for (int i = 0; i < n; i++) {
		string temp = "";
		for (int j = 0; j < n; j++) {
			temp += cross(v[i].first, v[i].second, v[j].first, v[j].second);
		}
		result.push_back(temp);
	}
	for (auto& i : result) {
		cout << i << '\n';
	}
	return 0;
}