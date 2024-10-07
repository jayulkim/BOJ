#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		int n = 0;
		ll k = 0;
		cin >> n >> k;
		vector<ll>v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int start = 0, end = n - 1;
		ll Min = 9876543210;
		int count = 1;
		while (start < end) {
			ll temp = v[start] + v[end] - k;
			if (temp <= 0) {
				start++;
			}
			else {
				end--;
			}
			if (Min > llabs(temp)) {
				count = 1;
				Min = llabs(temp);
			}
			else if (Min == llabs(temp)) {
				count++;
			}
		}
		cout << count << '\n';
	}
	return 0;
}