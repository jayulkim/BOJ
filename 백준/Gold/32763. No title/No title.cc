#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<bool>v;
	ll idx = 0;
	for (int i = 2; i <= n; i++) {
		cout << "? 1 * " << i << endl;
		char c;
		cin >> c;
		if (c == '+') {
			idx = i;
			v.push_back(true);
		}
		else {
			v.push_back(false);
		}
	}
	if (!idx) {
		char c;
		cout << "? 2 + 3" << endl;
		cin >> c;
		if (c == '+') {
			cout << "! - ";
			for (int i = 2; i <= n; i++) {
				cout << "+ ";
			}
			cout << endl;
		}
		else {
			cout << "! + ";
			for (int i = 2; i <= n; i++) {
				cout << "- ";
			}
			cout << endl;
		}
	}
	else {
		char c;
		cout << "? 1 + " << idx << endl;
		cin >> c;
		if (c == '+') {
			cout << "! + ";
			for (auto i : v) {
				if (!i) {
					cout << "- ";
				}
				else {
					cout << "+ ";
				}
			}
			cout << endl;
		}
		else {
			cout << "! - ";
			for (auto i : v) {
				if (!i) {
					cout << "+ ";
				}
				else {
					cout << "- ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}