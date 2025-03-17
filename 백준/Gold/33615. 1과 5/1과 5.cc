#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		string str = "";
		cin >> str;
		ll sum = 0;
		bool find = false;
		bool a = false;
		for (auto& i : str) {
			sum += i - '0';
			if (i == '1') {
				find = true;
			}
			else {
				a = true;
			}
		}
		if (sum % 3 == 0) {
			cout << 0 << ' ' << 3 << '\n';
		}
		else if (sum % 3 == 1) {
			if (find) {
				for (int i = 0; i < str.length(); i++) {
					if ((sum - (str[i] - '0')) % 3 == 0) {
						cout << i + 1 << ' ' << 3 << '\n';
						break;
					}
				}
			}
			else {
				cout << 0 << ' ' << 5 << '\n';
			}
		}
		else {
			if (a) {
				for (int i = 0; i < str.length(); i++) {
					if (str[i] == '5') {
						cout << i + 1 << ' ' << 3 << '\n';
						break;
					}
				}
			}
			else {
				if (str.length() % 2) {
					cout << 1 << ' ' << 11 << '\n';
				}
				else {
					cout << 0 << ' ' << 11 << '\n';
				}
			}
		}
	}
	return 0;
}