#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		ll command = 0, k = 0, j = 0;
		cin >> command;
		if (command == 1) {
			cin >> k;
			cout << n - (lower_bound(v.begin(), v.end(), k) - v.begin()) << '\n';
		}
		else if (command == 2) {
			cin >> k;
			cout << n - (upper_bound(v.begin(), v.end(), k) - v.begin()) << '\n';
		}
		else {
			cin >> k >> j;
			cout << (upper_bound(v.begin(), v.end(), j) - v.begin()) - (lower_bound(v.begin(), v.end(), k) - v.begin()) << '\n';
		}
	}
	return 0;
}