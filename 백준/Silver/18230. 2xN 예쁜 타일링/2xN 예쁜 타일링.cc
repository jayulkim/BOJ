#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	vector<int>one(m);
	vector<int>two(k);
	vector<int>v;
	for (int i = 0; i < m; i++) {
		cin >> one[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> two[i];
	}
	sort(one.begin(), one.end());
	sort(two.begin(), two.end());
	reverse(one.begin(), one.end());
	reverse(two.begin(), two.end());
	int result = 0;
	int idx1 = 0, idx2 = 0;
	if (n % 2 == 1) {
		if (idx1 < m) {
			result += one[idx1];
			idx1++;
		}
	}
	for (int i = 0; i < n / 2; i++) {
		if (idx1 < m - 1 && idx2 < n && one[idx1] + one[idx1 + 1] > two[idx2]) {
			result += (one[idx1] + one[idx1 + 1]);
			idx1 += 2;
		}
		else if (idx1 < m - 1 && idx2 < n) {
			result += two[idx2];
			idx2++;
		}
		else if (idx1 < m - 1) {
			result += (one[idx1] + one[idx1 + 1]);
			idx1 += 2;
		}
		else if (idx2 < n) {
			result += two[idx2];
			idx2++;
		}
	}
	cout << result;
	return 0;
}