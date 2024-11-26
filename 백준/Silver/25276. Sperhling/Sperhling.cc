#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a = "", b = "";
	cin >> a >> b;
	if (a == b) {
		cout << 0;
		return 0;
	}
	string str = "";
	ll idx = -1;
	for (int i = 0; i < min(a.length(), b.length()); i++) {
		if (a[i] != b[i]) {
			idx = i;
			break;
		}
		else {
			str += b[i];
		}
	}
	if (idx == -1) {
		cout << llabs(b.length() - a.length());
		return 0;
	}
	ll temp = a.length() - idx;
	cout << temp + b.length() - idx;
	return 0;
}