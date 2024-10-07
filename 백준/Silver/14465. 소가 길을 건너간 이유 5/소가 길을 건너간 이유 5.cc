#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0, k = 0;
int v[100001];
int sum[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		v[i] = 1;
	}
	for (int i = 0; i < k; i++) {
		int num = 0;
		cin >> num;
		v[num] = 0;
	}
	sum[1] = v[1];
	for (int i = 2; i <= n; i++) {
		sum[i] = sum[i - 1] + v[i];
	}
	int Max = 0;
	for (int i = m; i <= n; i++) {
		Max = max(Max, sum[i] - sum[i - m]);
	}
	if (Max >= m) {
		cout << 0;
	}
	else {
		cout << m - Max;
	}
	return 0;
}