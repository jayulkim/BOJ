#include <bits/stdc++.h>
using namespace std;
int ary[100001][3];
int maxdp[100001][3];
int mindp[100001][3];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ary[i][0] >> ary[i][1] >> ary[i][2];
	}
	maxdp[0][0] = ary[0][0];
	maxdp[0][1] = ary[0][1];
	maxdp[0][2] = ary[0][2];
	mindp[0][0] = ary[0][0];
	mindp[0][1] = ary[0][1];
	mindp[0][2] = ary[0][2];
	for (int i = 1; i < n; i++) {
		maxdp[i][0] = max(maxdp[i - 1][0], maxdp[i - 1][1]) + ary[i][0];
		maxdp[i][1] = max(max(maxdp[i - 1][0], maxdp[i - 1][1]), maxdp[i - 1][2]) + ary[i][1];
		maxdp[i][2] = max(maxdp[i - 1][1], maxdp[i - 1][2]) + ary[i][2];
		mindp[i][0] = min(mindp[i - 1][0], mindp[i - 1][1]) + ary[i][0];
		mindp[i][1] = min(min(mindp[i - 1][0], mindp[i - 1][1]), mindp[i - 1][2]) + ary[i][1];
		mindp[i][2] = min(mindp[i - 1][1], mindp[i - 1][2]) + ary[i][2];
	}
	cout << max(max(maxdp[n - 1][0], maxdp[n - 1][1]), maxdp[n - 1][2]) << ' ' << min(min(mindp[n - 1][0], mindp[n - 1][1]), mindp[n - 1][2]);
	return 0;
}