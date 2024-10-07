#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
pld vec(pld a, pld b) {
	return { b.first - a.first, b.second - a.second };
}
ll ccw(pld a, pld b, pld c) {
	pld p1 = vec(a, b);
	pld p2 = vec(b, c);
	ld temp = p1.first * p2.second - p2.first * p1.second;
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
ll cross(pld s1, pld e1, pld s2, pld e2) {
	if (s1 > e1) {
		swap(s1, e1);
	}
	if (s2 > e2) {
		swap(s2, e2);
	}
	ll a = ccw(s1, e1, s2) * ccw(s1, e1, e2);
	ll b = ccw(s2, e2, s1) * ccw(s2, e2, e1);
	if (!a && !b) {
		return 0;
	}
	if (a < 0 && b < 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	pld a = { 0,0 }, b = { 0,0 };
	pld c = { 0,0 }, d = { 0,0 };
	cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
	cout << cross(a, b, c, d);
	return 0;
}