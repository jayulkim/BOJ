#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n;
		vector<ll>v(4);
		ll sum = 0;
		for (int i = 0; i < min(n, (ll)4); i++) {
			cin >> v[i];
			sum += v[i];
		}
		vector<bool>p1(n + 1, 0);
		vector<bool>p2(n + 1, 0);
		vector<bool>p3(n + 1, 0);
		vector<bool>p4(n + 1, 0);
		ll a = 0, b = 0, c = 0, d = 0, e = 0;
		if (n <= 4) {
			cout << "YES\n";
			cout << 0;
			for (int i = 0; i < n - 1; i++) {
				cout << n - 1;
			}
			cout << '\n';
			continue;
		}
		a = v[0];
		b = v[1] + a;
		c = v[2] + b;
		d = v[3] + c;
		for (int i = 4; i < n; i++) {
			cin >> k;
			sum += k;
			e = max({ a + v[2] + v[3] + k, b + v[3] + k, c + k, d });
			if (e == a + v[2] + v[3] + k) {
				p1[i] = 1;
				p2[i] = 1;
			}
			else if (e == b + v[3] + k) {
				p1[i] = 1;
				p2[i] = 0;
			}
			else if (e == c + k) {
				p1[i] = 0;
				p2[i] = 1;
			}
			else if (e == d) {
				p1[i] = 0;
				p2[i] = 0;
			}
			a = b;
			b = c;
			c = d;
			d = e;
			v[0] = v[1];
			v[1] = v[2];
			v[2] = v[3];
			v[3] = k;
		}
		if (sum * 3 > 4 * e) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		ll idx = n - 1;
		while (idx >= 4) {
			if (p1[idx] && p2[idx]) {
				p3[idx] = 1;
				p4[idx] = 1;
				p3[idx - 1] = 1;
				p4[idx - 1] = 1;
				p3[idx - 2] = 1;
				p4[idx - 2] = 1;
				p3[idx - 3] = 0;
				p4[idx - 3] = 0;
				idx -= 4;
			}
			else if (p1[idx] && !p2[idx]) {
				p3[idx] = 1;
				p4[idx] = 0;
				p3[idx - 1] = 1;
				p4[idx - 1] = 0;
				p3[idx - 2] = 0;
				p4[idx - 2] = 0;
				idx -= 3;
			}
			else if (!p1[idx] && p2[idx]) {
				p3[idx] = 0;
				p4[idx] = 1;
				p3[idx - 1] = 0;
				p4[idx - 1] = 0;
				idx -= 2;
			}
			else {
				p3[idx] = 0;
				p4[idx] = 0;
				idx--;
			}
		}
		if (idx == 3) {
			p3[idx] = 1;
			p4[idx] = 1;
			p3[idx - 1] = 1;
			p4[idx - 1] = 1;
			p3[idx - 2] = 1;
			p4[idx - 2] = 1;
			p3[idx - 3] = 0;
			p4[idx - 3] = 0;
		}
		else if (idx == 2) {
			p3[idx] = 1;
			p4[idx] = 0;
			p3[idx - 1] = 1;
			p4[idx - 1] = 0;
			p3[idx - 2] = 0;
			p4[idx - 2] = 0;
		}
		else if (idx == 1) {
			p3[idx] = 0;
			p4[idx] = 1;
			p3[idx - 1] = 0;
			p4[idx - 1] = 0;
		}
		else {
			p3[idx] = 0;
			p4[idx] = 0;
		}
		for (int i = 0; i < n; i++) {
			if (p3[i] && p4[i]) {
				cout << 3;
			}
			else if (p3[i] && !p4[i]) {
				cout << 2;
			}
			else if (!p3[i] && p4[i]) {
				cout << 1;
			}
			else {
				cout << 0;
			}
		}
		cout << '\n';
	}
	return 0;
}