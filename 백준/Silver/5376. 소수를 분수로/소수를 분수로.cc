#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
string str = "";
ll gcd(ll a, ll b) {
	ll temp = a % b;
	while (temp > 0) {
		a = b;
		b = temp;
		temp = a % b;
	}
	return b;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		string str = "";
		cin >> str;
		bool find = false;
		ll idx = -1;
		string up = "";
		string down = "";
		string upup = "";
		for (int i = 0; i < str.length(); i++) {
			if (find && isdigit(str[i])) {
				down += '9';
			}
			if (!find && idx != -1 && isdigit(str[i])) {
				down += '0';
				upup += str[i];
			}
			if (str[i] == '(') {
				find = true;
			}
			if (str[i] == '.') {
				idx = i;
			}
		}
		if (!find) {
			down += '1';
		}
		reverse(down.begin(), down.end());
		for (int i = idx + 1; i < str.length(); i++) {
			if (isdigit(str[i])) {
				up += str[i];
			}
		}
		ll upupup = stoll(up);
		if (find && upup != "") {
			upupup -= stoll(upup);
		}
		cout << upupup / gcd(upupup, stoll(down)) << '/' << stoll(down) / gcd(upupup, stoll(down)) << '\n';
	}
	return 0;
}