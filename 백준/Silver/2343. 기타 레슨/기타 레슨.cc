#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v(n);
	int Max = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		Max = max(Max, v[i]);
	}
	int start = Max, end = 1000000001, mid = 0;
	while (start < end) {
		mid = (start + end) / 2;
		int count = 1;
		int temp = 0;
		for (int i = 0; i < n; i++) {
			if (temp + v[i] > mid) {
				temp = v[i];
				count++;
			}
			else {
				temp += v[i];
			}
		}
		if (count <= m) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}
	cout << end;
	return 0;
}