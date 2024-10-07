#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll, ll> vec(ll x1, ll y1, ll x2, ll y2) {
	return { x2 - x1, y2 - y1 };
}
ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	pair<ll, ll>a = vec(x1, y1, x2, y2);
	pair<ll, ll>b = vec(x2, y2, x3, y3);
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
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cout << ccw(x1, y1, x2, y2, x3, y3);
	return 0;
}