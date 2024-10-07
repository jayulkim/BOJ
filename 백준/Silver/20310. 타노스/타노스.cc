#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	cin >> str;
	for (auto& i : str) {
		if (i == '0') {
			n++;
		}
		else {
			m++;
		}
	}
	n /= 2;
	m /= 2;
	for (int i = 0; i < str.length(); i++) {
		if (!m) {
			break;
		}
		if (str[i] == '1') {
			str[i] = '-';
			m--;
		}
	}
	for (int i = str.length() - 1; i >= 0; i--) {
		if (!n) {
			break;
		}
		if (str[i] == '0') {
			str[i] = '-';
			n--;
		}
	}
	for (auto& i : str) {
		if (i != '-') {
			cout << i;
		}
	}
	return 0;
}