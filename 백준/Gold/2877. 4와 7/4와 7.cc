#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	n++;
	string result = "";
	while (n > 0) {
		if (n % 2) {
			result += '1';
		}
		else {
			result += '0';
		}
		n /= 2;
	}
	string temp = "";
	reverse(result.begin(), result.end());
	for (int i = 1; i < result.length(); i++) {
		if (result[i] == '0') {
			temp += '4';
		}
		else {
			temp += '7';
		}
	}
	cout << temp;
	return 0;
}