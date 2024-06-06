#include <bits/stdc++.h>
using namespace std;
int dpleft[300001];
int dpright[300001];
int ary[300001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>leftv(n);
	vector<int>rightv(n);
	for (int i = 0; i < n; i++) {
		cin >> leftv[i];
	}
	for (int i = 0; i < n; i++) {
		rightv[i] = leftv[n - i - 1] * -1;
	}
	ary[0] = leftv[0];
	int idx = 0;
	for (int i = 0; i < n; i++) {
		int start = 0;
		int end = idx;
		int mid = 0;
		if (ary[idx] < leftv[i]) {
			ary[++idx] = leftv[i];
			dpleft[i] = idx + 1;
		}
		else {
			while (start < end) {
				mid = (start + end) / 2;
				if (ary[mid] >= leftv[i]) {
					end = mid;
				}
				else {
					start = mid + 1;
				}
			}
			ary[end] = leftv[i];
			dpleft[i] = end + 1;
		}
	}
	idx = 0;
	memset(ary, 0, sizeof(ary));
	for (int i = 0; i < n; i++) {
		int start = 0;
		int end = idx;
		int mid = 0;
		if (ary[idx] < rightv[i]) {
			ary[++idx] = rightv[i];
			dpright[i] = idx + 1;
		}
		else {
			while (start < end) {
				mid = (start + end) / 2;
				if (ary[mid] >= rightv[i]) {
					end = mid;
				}
				else {
					start = mid + 1;
				}
			}
			ary[end] = rightv[i];
			dpright[i] = end + 1;
		}
	}
	for (int i = 0; i < m; i++) {
		int idx = 0;
		cin >> idx;
		cout << dpleft[idx - 1] + dpright[n - idx] - 1 << '\n';
	} 
	return 0;
}