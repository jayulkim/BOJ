#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	if (n < m || m == 1) {
		cout << "NO";
		return 0;
	}
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++) {
		v[i] = i;
	}
	if (m % 2 == 0) {
		cout << "YES" << '\n';
		for (int i = 1; i <= n; i++) {
			cout << i << ' ';
			if (i % m == 0) {
				cout << '\n';
			}
		}
	}
	else {
		if (n == m) {
			cout << "NO";
			return 0;
		}
		if ((n / m) % 2 == 0) {
			cout << "YES" << '\n';
			for (int i = m; i < n; i += 2 * m) {
				if (i % m == 0) {
					swap(v[i], v[i + 1]);
				}
			}
			for (int i = 1; i <= n; i++) {
				cout << v[i] << ' ';
				if (i % m == 0) {
					cout << '\n';
				}
			}
		}
		else {
			cout << "YES" << '\n';
			for (int i = m; i < n; i += 2 * m) {
				if (i % m == 0) {
					swap(v[i], v[i + 1]);
				}
			}
			swap(v[m * (n / m - 1)], v[m * (n / m - 1) + 2]);
			for (int i = 1; i <= n; i++) {
				cout << v[i] << ' ';
				if (i % m == 0) {
					cout << '\n';
				}
			}
		}
	}
	return 0;
}