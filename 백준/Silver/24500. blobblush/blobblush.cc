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
	ll num = n;
	string result = "";
	while (n > 0) {
		result += to_string(n % 2);
		n /= 2;
	}
	for (auto& i : result) {
		if (i == '0') {
			cout << 2 << '\n';
			ll temp = 0;
			ll count = 1;
			for (auto& i : result) {
				if (i == '0') {
					temp += (count);
				}
				count *= 2;
			}
			cout << temp << ' ' << num;
			return 0;
		}
	}
	cout << 1 << '\n';
	cout << num;
	return 0;
}