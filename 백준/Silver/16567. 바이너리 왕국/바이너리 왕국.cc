#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	int count = 0;
	bool prev = false;
	if (v[1] == 1) {
		prev = true;
		count++;
	}
	for (int i = 2; i <= n; i++) {
		if (v[i] == 1) {
			if (!prev) {
				count++;
			}
			prev = true;
		}
		else {
			prev = false;
		}
	}
	for (int i = 0; i < m; i++) {
		int command = 0, x = 0;
		cin >> command;
		if (command == 1) {
			cin >> x;
			if (!v[x]) {
				if (x >= 2 && v[x - 1] == 1 && x <= n - 1 && v[x + 1] == 1) {
					count--;
				}
				else if (x >= 2 && !v[x - 1] && x <= n - 1 && !v[x + 1]) {
					count++;
				}
				else if (x == 1 && !v[x + 1]) {
					count++;
				}
				else if (x == n && !v[x - 1]) {
					count++;
				}
				v[x] = 1;
			}
		}
		else {
			cout << count << '\n';
		}
	}
	return 0;
}