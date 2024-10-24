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
		bool Find = false;
		for (int i = 2; i <= 64; i++) {
			vector<ll>result;
			ll temp = n;
			while (temp > 0) {
				result.push_back(temp % i);
				temp /= i;
			}
			reverse(result.begin(), result.end());
			bool find = false;
			for (int i = 0; i < result.size() / 2; i++) {
				if (result[i] != result[result.size() - 1 - i]) {
					find = true;
					break;
				}
			}
			if (!find) {
				cout << 1 << '\n';
				Find = true;
				break;
			}
		}
		if (!Find) {
			cout << 0 << '\n';
		}
	}
	return 0;
}