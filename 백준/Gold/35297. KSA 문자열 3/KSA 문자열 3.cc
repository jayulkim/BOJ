#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	cin >> str;
	ll idx = str.length() - 1;
	for (int i = str.length(); i >= 0; i--) {
		ll temp = 0;
		if (str[i] == 'K') {
			temp = 1;
		}
		else if (str[i] == 'S') {
			temp = 2;
		}
		if (temp == (idx + 1) % 3 && (idx - i) % 2 == 0) {
			idx--;
		}
	}
	cout << 2 * (str.length() - (str.length() - 1 - idx));
	return 0;
}