#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		ll n = 0;
		cin >> n;
		ll exp = n * (n + 1) / 2;
		ll result = 0;
		ll start = 1, end = 10e18 / 2, mid = 0;
		while (start <= end) {
			mid = (start + end) / 2;
			if (mid * (mid + 1) > exp) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
				result = mid;
			}
		}
		cout << result + 1 << '\n';
	}
	return 0;
}