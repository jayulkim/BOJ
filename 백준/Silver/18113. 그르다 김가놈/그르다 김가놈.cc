#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll>v;
	ll Max = 0;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		if (num > 2 * m) {
			v.push_back(num - 2 * m);
			Max = max(Max, num - 2 * m);
		}
		else if (num > m && num != 2 * m) {
			v.push_back(num - m);
			Max = max(Max, num - m);
		}
	}
	ll sum = 0;
	for (auto& i : v) {
		sum += i;
	}
	if (sum < k) {
		cout << -1;
		return 0;
	}
	ll start = 0, end = Max, mid = 0;
	ll result = 0;
	while (start <= end) {
		int temp = 0;
		mid = (start + end) / 2;
		if (mid == 0) {
			start++;
			goto back;
		}
		for (auto& i : v) {
			temp += i / mid;
		}
		if (temp < k) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
			result = mid;
		}
	back:
		continue;
	}
	cout << result;
	return 0;
}