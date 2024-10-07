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
ll cross(pll start1, pll end1, pll start2, pll end2) {
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
		if (start1 <= end2 && start2 <= end1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (a * b <= 0 && c * d <= 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	pll start1 = { 0, 0 }, end1 = { 0, 0 };
	pll start2 = { 0, 0 }, end2 = { 0, 0 };
	cin >> start1.first >> start1.second >> end1.first >> end1.second;
	cin >> start2.first >> start2.second >> end2.first >> end2.second;
	cout << cross(start1, end1, start2, end2);
	return 0;
}