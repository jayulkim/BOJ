#include <bits/stdc++.h>
using namespace std;
int dp[200001];
bool visited[200001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	dp[0] = v[0];
	int idx = 0;
	vector<int>ary(n);
	for (int i = 1; i < n; i++) {
		if (dp[idx] <= v[i]) {
			dp[++idx] = v[i];
			ary[i] = idx;
		}
		else {
			int start = 0, end = idx, mid = 0;
			while (start < end) {
				mid = (start + end) / 2;
				if (dp[mid] > v[i]) {
					end = mid;
				}
				else {
					start = mid + 1;
				}
			}
			dp[end] = v[i];
			ary[i] = end;
		}
	}
	if (n - idx - 1 > 3) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << '\n';
	cout << n - idx - 1 << '\n';
	for (int i = n - 1; i >= 0; i--) {
		if (ary[i] == idx) {
			visited[i] = true;
			idx--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (i == 0) {
				v[i] = 1;
				cout << 1 << ' ' << v[i] << '\n';
			}
			else {
				v[i] = v[i - 1];
				cout << i + 1 << ' ' << v[i - 1] << '\n';
			}
		}
	}
	return 0;
}