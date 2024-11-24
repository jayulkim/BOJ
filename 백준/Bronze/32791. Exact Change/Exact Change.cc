#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a = "", b = "";
	cin >> a >> b;
	ll result = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (a.length() < b.length()) {
		a += '0';
	}
	for (int i = a.length() - 1; i >= 0; i--) {
		if (a[i] == '0' && b[i] == '1') {
			result += (i + 1);
			break;
		}
		else if (b[i] == '1') {
			result++;
		}
	}
	cout << result;
	return 0;
}