#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if (!m) {
		cout << n - 1;
	}
	else {
		m--;
		if (n != 1 && n != 5) {
			ll result = 5;
			if (m % 2 == 0) {
				result += (8 * (m / 2));
				result += (5 - n - 1);
			}
			else {
				result += (8 * (m / 2));
				result += 4;
				result += (n - 2);
			}
			cout << result;
		}
		else if (n == 1) {
			ll result = 5;
			result += (m * 8);
			result += 3;
			cout << result;
		}
		else if (n == 5) {
			ll result = 5;
			result += 4;
			result += (8 * m);
			result += 3;
			cout << result;
		}
	}
	return 0;
}