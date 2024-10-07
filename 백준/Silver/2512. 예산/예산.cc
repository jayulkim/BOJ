#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	ll m = 0;
	cin >> n;
	vector<ll>v(n);
	ll Max = 0;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		Max = max(Max, v[i]);
		sum += v[i];
	}
	cin >> m;
	if (sum <= m) {
		cout << Max;
		return 0;
	}
	ll start = 1, end = Max, mid = 0;
	while (start < end) {
		mid = (start + end) / 2;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid >= v[i]) {
				sum += v[i];
			}
			else {
				sum += mid;
			}
		}
		if (sum > m) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}
	cout << end - 1;
	return 0;
}