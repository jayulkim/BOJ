#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n = 0, m = 0;
struct info {
	ll weight;
	ll worth;
	ll count;
};
ll dp[2001][10001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll>v(20);
	v[0] = 1;
	v[1] = 2;
	for (int i = 2; i < 20; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
	cin >> n >> m;
	vector<info>ary(n);
	vector<info>List;
	for (int i = 0; i < n; i++) {
		cin >> ary[i].weight >> ary[i].worth >> ary[i].count;
		int idx = 0;
		while (idx < 20 && ary[i].count > 0) {
			if (v[idx] <= ary[i].count) {
				List.push_back({ ary[i].weight * v[idx], ary[i].worth * v[idx], 0 });
				ary[i].count -= v[idx];
				idx++;
			}
			else {
				List.push_back({ ary[i].weight * ary[i].count, ary[i].worth * ary[i].count, 0});
				break;
			}
		}
	}
	for (int i = 0; i < List.size(); i++) {
		for (int j = 1; j <= m; j++) {
			if (j >= List[i].weight) {
				dp[i + 1][j] = max(dp[i][j - List[i].weight] + List[i].worth, dp[i][j]);
			}
			else {
				dp[i + 1][j] = dp[i][j];
			}
		}
	}
	cout << dp[List.size()][m];
	return 0;
}