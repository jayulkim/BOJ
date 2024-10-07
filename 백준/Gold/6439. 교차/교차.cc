#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
pll vec(ll x1, ll y1, ll x2, ll y2) {
	return { x2 - x1, y2 - y1 };
}
ll ccw(pll p1, pll p2, pll p3) {
	pll a = vec(p1.first, p1.second, p2.first, p2.second);
	pll b = vec(p2.first, p2.second, p3.first, p3.second);
	ll temp = a.first * b.second - a.second * b.first;
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
bool cross(pll start1, pll end1, pll start2, pll end2) {
	if (start1 > end1) {
		swap(start1, end1);
	}
	if (start2 > end2) {
		swap(start2, end2);
	}
	ll a = ccw(start1, end1, start2);
	ll b = ccw(start1, end1, end2);
	ll c = ccw(start2, end2, start1);
	ll d = ccw(start2, end2, end1);
	if (a * b == 0 && c * d == 0) {
		return start1 <= end2 && start2 <= end1;
	}
	return a * b <= 0 && c * d <= 0;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		pll start1 = { 0, 0 }, end1 = { 0, 0 };
		ll x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> start1.first >> start1.second >> end1.first >> end1.second;
		cin >> x1 >> y1 >> x2 >> y2;
		pll p1 = { x1, y1 }, p2 = { x1, y2 }, p3 = { x2, y1 }, p4 = { x2, y2 };
		bool a = cross(start1, end1, p1, p2);
		bool b = cross(start1, end1, p1, p3);
		bool c = cross(start1, end1, p2, p4);
		bool d = cross(start1, end1, p3, p4);
		if (start1 > end1) {
			swap(start1, end1);
		}
		if (!a && !b && !c && !d) {
			if (min(start1.first, end1.first) > min(p1.first, p4.first) && min(start1.second, end1.second) > min(p1.second, p4.second) && max(start1.first, end1.first) < max(p1.first, p4.first) && max(start1.second, end1.second) < max(p1.second, p4.second)) {
				cout << 'T' << '\n';
			}
			else {
				cout << 'F' << '\n';
			}
		}
		else {
			cout << 'T' << '\n';
		}
	}
	return 0;
}