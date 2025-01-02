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
	string a = "", b = "";
	cin >> a >> b;
	while (b.length() > a.length()) {
		if (b.back() == 'A') {
			b.pop_back();
		}
		else if (b.back() == 'B') {
			b.pop_back();
			reverse(b.begin(), b.end());
		}
	}
	if (a != b) {
		cout << 0;
	}
	else {
		cout << 1;
	}
	return 0;
}