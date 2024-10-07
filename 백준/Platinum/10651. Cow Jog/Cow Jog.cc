#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	ll t = 0;
	cin >> n >> t;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		ll start = 0, sp = 0;
		cin >> start >> sp;
		v[i] = start + t * sp;
	}
	reverse(v.begin(), v.end());
	dp[0] = v[0];
	int idx = 0;
	for (int i = 1; i < n; i++) {
		if (dp[idx] <= v[i]) {
			dp[++idx] = v[i];
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
		}
	}
	cout << idx + 1;
	return 0;
}