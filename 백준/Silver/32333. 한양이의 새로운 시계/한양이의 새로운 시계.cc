#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<string>ary = { "rat", "cow", "tiger", "rabbit", "dragon", "snake", "horse", "sheep", "monkey", "chicken", "dog", "pig", "lion", "giraffe", "cat" };
vector<pll>t;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a = 0, b = 95;
	for (int i = 0; i < 15; i++) {
		t.push_back({ a, b });
		a += 96;
		b += 96;
	}
	cin >> n;
	vector<tp>v;
	for (int i = 0; i < n; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		v.push_back({ a, b, c });
	}
	sort(v.begin(), v.end());
	auto [aa, bb, cc] = v[0];
	ll start = aa * 60 + bb;
	ll end = start + cc;
	if (end >= 1440) {
		cout << n;
		return 0;
	}
	vector<string>result;
	ll ss = 0, tt = 0;
	for (int i = 0; i < t.size(); i++) {
		if (start >= t[i].first && start <= t[i].second) {
			ss = i;
			break;
		}
	}
	for (int i = 0; i < t.size(); i++) {
		if (end >= t[i].first && end <= t[i].second) {
			tt = i;
			break;
		}
	}
	for (int i = ss; i <= tt; i++) {
		result.push_back(ary[i]);
	}
	for (auto& i : result) {
		cout << i << ' ';
	}
	cout << '\n';
	ll z = start / 60;
	ll x = start % 60;
	string d = "";
	if (z < 10) {
		d += '0';
	}
	d += to_string(z);
	string e = "";
	if (x < 10) {
		e += '0';
	}
	e += to_string(x);
	ll f = 0, g = 0;
	f = end / 60;
	g = end % 60;
	string h = "", j = "";
	if (f < 10) {
		h += '0';
	}
	h += to_string(f);
	if (g < 10) {
		j += '0';
	}
	j += to_string(g);
	cout << d << ':' << e << ' ' << h << ':' << j << '\n';
	ll count = 0;
	for (int i = 1; i < n; i++) {
		auto [a, b, c] = v[i];
		start = max(end, a * 60 + b);
		end = start + c;
		if (end >= 1440) {
			count++;
		}
		else {
			if (max(a * 60 + b, start) + c >= end) {
				vector<string>result;
				ll ss = 0, tt = 0;
				for (int i = 0; i < t.size(); i++) {
					if (start >= t[i].first && start <= t[i].second) {
						ss = i;
						break;
					}
				}
				for (int i = 0; i < t.size(); i++) {
					if (end >= t[i].first && end <= t[i].second) {
						tt = i;
						break;
					}
				}
				for (int i = ss; i <= tt; i++) {
					result.push_back(ary[i]);
				}
				for (auto& i : result) {
					cout << i << ' ';
				}
				cout << '\n';
				ll z = start / 60;
				ll x = start % 60;
				string d = "";
				if (z < 10) {
					d += '0';
				}
				d += to_string(z);
				string e = "";
				if (x < 10) {
					e += '0';
				}
				e += to_string(x);
				ll f = 0, g = 0;
				f = end / 60;
				g = end % 60;
				string h = "", j = "";
				if (f < 10) {
					h += '0';
				}
				h += to_string(f);
				if (g < 10) {
					j += '0';
				}
				j += to_string(g);
				cout << d << ':' << e << ' ' << h << ':' << j << '\n';
			}
		}
	}
	if (count) {
		cout << count;
	}
	return 0;
}