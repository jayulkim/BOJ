#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
string str = "";
vector<ll>v(10, 0);
ll comb(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	ll up = 1;
	ll down = 1;
	for (ll i = a; i >= a - b + 1; i--) {
		up *= i;
	}
	for (ll i = 2; i <= b; i++) {
		down *= i;
	}
	return up / down;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	for (int i = 1; i <= str.length() - 1; i++) {
		for (int j = 1; j <= i - 1; j++) {
			for (int k = 0; k < 10; k++) {
				if (!k) {
					v[k] += j * comb(i - 1, j) * pow(9, i - j - 1) * 9;
				}
				else {
					v[k] += j * comb(i - 1, j - 1) * pow(9, i - j);
					v[k] += j * comb(i - 1, j) * pow(9, i - j - 1) * 8;
				}
			}
		}
		for (int j = 1; j < 10; j++) {
			v[j] += i;
		}
	}
	for (int i = 1; i < str[0] - '0'; i++) {
		v[i] += pow(9, str.length() - 1);
	}
	for (int i = 1; i <= str.length() - 1; i++) {
		v[0] += i * comb(str.length() - 1, i) * (str[0] - '0' - 1) * pow(9, str.length() - 1 - i);
		for (int j = 1; j < 10; j++) {
			if (j <= str[0] - '0' - 1) {
				v[j] += (str[0] - '0' - 2) * comb(str.length() - 1, i) * pow(9, str.length() - 1 - i) * i;
				v[j] += (i + 1) * comb(str.length() - 1, i) * pow(9, str.length() - 1 - i);
			}
			else {
				v[j] += (str[0] - '0' - 1) * comb(str.length() - 1, i) * pow(9, str.length() - 1 - i) * i;
			}
		}
	}
	string temp = "";
	temp += str[0];
	while (temp.length() < str.length()) {
		temp += '0';
	}
	n = stoll(temp);
	m = stoll(str);
	for (int i = n; i <= m; i++) {
		ll num = i;
		while (num > 0) {
			v[num % 10]++;
			num /= 10;
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << v[i] << ' ';
	}
	return 0;
}