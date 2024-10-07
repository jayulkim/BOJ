#include <bits/stdc++.h>
using namespace std;
int dp[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	int k = 0;
	cin >> k;
	vector<pair<int, int>>v;
	for (int i = 0; i < k; i++) {
		int x = 0, y = 0;
		cin >> y >> x;
		if (x <= m && y <= n) {
			v.push_back({ x, y });
		}
	}
	sort(v.begin(), v.end());
	dp[0] = v[0].second;
	int idx = 0;
	for (int i = 1; i < v.size(); i++) {
		if (dp[idx] <= v[i].second) {
			dp[++idx] = v[i].second;
		}
		else {
			int start = 0, end = idx, mid = 0;
			while (start < end) {
				mid = (start + end) / 2;
				if (dp[mid] > v[i].second) {
					end = mid;
				}
				else {
					start = mid + 1;
				}
			}
			dp[end] = v[i].second;
 		}
	}
	cout << idx + 1;
	return 0;
}