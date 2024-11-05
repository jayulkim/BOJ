#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		ll n = 0;
		cin >> n;
		string a = "", b = "";
		cin >> a >> b;
		ll count = 0;
		ll c = 0, d = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 'B') {
				c++;
			}
			if (b[i] == 'B') {
				d++;
			}
			if (a[i] != b[i]) {
				count++;
			}
		}
		cout << llabs(c - d) + (count - llabs(c - d)) / 2 << '\n';
	}
	return 0;
}