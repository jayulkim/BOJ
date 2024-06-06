#include <bits/stdc++.h>
using namespace std;
int dpleft[3001];
int dpright[3001];
int leftary[3001];
int rightary[3001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> leftary[i];
	}
	for (int i = 1; i <= n; i++) {
		int Max = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (leftary[i] > leftary[j]) {
				Max = max(Max, dpleft[j]);
			}
		}
		dpleft[i] = Max + 1;
	}
	for (int i = 1; i <= n; i++) {
		rightary[i] = leftary[n - i + 1] * -1;
	}
	for (int i = 1; i <= n; i++) {
		int Max = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (rightary[i] > rightary[j]) {
				Max = max(Max, dpright[j]);
			}
		}
		dpright[i] = Max + 1;
	}
	for (int i = 0; i < m; i++) {
		int idx = 0;
		cin >> idx;
		cout << dpleft[idx] + dpright[n - idx + 1] - 1 << '\n';
	}
	return 0; 
}