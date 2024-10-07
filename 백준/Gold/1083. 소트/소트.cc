#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> k;
	int idx = 0;
	while (k > 0 && idx < n) {
		int count = 0;
		int Max = 0;
		int temp = 0;
		for (int i = idx; i < n; i++) {
			if (v[i] > v[idx] && i - idx <= k) {
				if (v[i] > Max) {
					Max = v[i];
					count = i;
				}
				temp++;
			}
		}
		if (temp != 0) {
			v.insert(v.begin() + idx, v[count]);
			v.erase(v.begin() + count + 1, v.begin() + count + 2);
			k -= (count - idx);
		}
		idx++;
	}
	for (auto& i : v) {
		cout << i << ' ';
	}
	return 0;
}