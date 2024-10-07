#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int Max = 0;
	int cost = 0;
	if (m > n) {
		for (int i = m - n; i < m; i++) {
			if (Max < v[i] * (m - i)) {
				Max = v[i] * (m - i);
				cost = v[i];
			}
		}
	}
	else {
		for (int i = 0; i < m; i++) {
			if (Max < v[i] * (m - i)) {
				Max = v[i] * (m - i);
				cost = v[i];
			}
		}
	}
	cout << cost << ' ' << Max;
	return 0;
}