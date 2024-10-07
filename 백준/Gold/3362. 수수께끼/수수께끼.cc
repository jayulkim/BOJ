#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		ll n = 0, m = 0;
		cin >> n >> m;
		vector<ll>v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int start = 0, end = n, mid = 0;
		bool find = false;
		while (start < end) {
			mid = (start + end) / 2;
			vector<ll>ary;
			for (int i = 0; i <= mid; i++) {
				ary.push_back(v[i]);
			}
			sort(ary.begin(), ary.end());
			ll sum = 0;
			for (auto& i : ary) {
				if (sum + 1 < i) {
					break;
				}
				sum += i;
			}
			if (sum >= m) {
				end = mid;
				find = true;
			}
			else {
				start = mid + 1;
			}
		}
		if (!find) {
			cout << -1 << '\n';
		}
		else {
			cout << end + 1 << '\n';
		}
	}
	return 0;
}