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
char cross(pld start1, pld end1, pld start2, pld end2) {
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
		if (start1 <= end2 && start2 <= end1) {
			if (start1.first == end1.first && start2.first == end2.first) {
				if (start1 > start2) {
					swap(start1, start2);
					swap(end1, end2);
				}
				if (start1.first == start2.first && start2 == end1) {
					return '1';
				}
				return '3';
			}
			else if ((end2.second - start2.second) * (end1.first - start1.first) == (end1.second - start1.second) * (end2.first - start2.first)) {
				if (start1 > start2) {
					swap(start1, start2);
					swap(end1, end2);
				}
				if (start2 == end1) {
					return '1';
				}
				return '3';
			}
			else {
				if (start1 == start2 || start1 == end2) {
					return '1';
				}
				if (end1 == start2 || end1 == end2) {
					return '1';
				}
				return '3';
			}
		}
		else {
			return '0';
		}
	}
	if (a * b <= 0 && c * d <= 0) {
		if (start1 > start2) {
			swap(start1, start2);
			swap(end1, end2);
		}
		if (!ccw(start1, end1, start2) || !ccw(start1, end1, end2) || !ccw(start1, start2, end2) || !ccw(end1, start2, end2)) {
			return '1';
		}
		return '2';
	}
	else {
		return '0';
	}
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