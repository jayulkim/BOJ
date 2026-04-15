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
bool Find = false;
ld x = 0, y = 0;
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
		if (start1 <= end2 && start2 <= end1) {
			if (start1.first == end1.first && start2.first == end2.first) {
				if (start1 > start2) {
					swap(start1, start2);
					swap(end1, end2);
				}
				if (start1.first == start2.first && start2 == end1) {
					Find = true;
					x = end1.first;
					y = end1.second;
				}
			}
			else if ((end2.second - start2.second) * (end1.first - start1.first) == (end1.second - start1.second) * (end2.first - start2.first)) {
				if (start1 > start2) {
					swap(start1, start2);
					swap(end1, end2);
				}
				if (start2 == end1) {
					Find = true;
					x = end1.first;
					y = end1.second;
				}
			}
			else {
				Find = true;
				if (start1 == start2 || start1 == end2) {
					x = start1.first;
					y = start1.second;
				}
				if (end1 == start2 || end1 == end2) {
					x = end1.first;
					y = end1.second;
				}
			}
			return true;
		}
		else {
			return false;
		}
	}
	if (a * b <= 0 && c * d <= 0) {
		if (start1.first == end1.first) {
			x = start1.first;
			y = (end2.second - start2.second) / (end2.first - start2.first) * (x - start2.first) + start2.second;
		}
		else if (start2.first == end2.first) {
			x = start2.first;
			y = (end1.second - start1.second) / (end1.first - start1.first) * (x - start1.first) + start1.second;
		}
		else {
			x = ((end1.second - start1.second) * (end2.first - start2.first) * start1.first - (end2.second - start2.second) * (end1.first - start1.first) * start2.first + (end1.first - start1.first) * (end2.first - start2.first) * (start2.second - start1.second)) / ((end1.second - start1.second) * (end2.first - start2.first) - (end2.second - start2.second) * (end1.first - start1.first));
			y = (end1.second - start1.second) / (end1.first - start1.first) * (x - start1.first) + start1.second;
		}
		Find = true;
		return true;
	}
	else {
		return false;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	pld start1 = { 0, 0 }, end1 = { 0, 0 };
	pld start2 = { 0, 0 }, end2 = { 0, 0 };
	cin >> start1.first >> start1.second >> end1.first >> end1.second;
	cin >> start2.first >> start2.second >> end2.first >> end2.second;
	if (!cross(start1, end1, start2, end2)) {
		cout << 0;
	}
	else {
		cout << 1 << '\n';
		if (Find) {
			cout << fixed;
			cout.precision(30);
			cout << x << ' ' << y;
		}
	}
	return 0;
}