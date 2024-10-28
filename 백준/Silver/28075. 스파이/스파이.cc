#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
ll Map[3][4];
vector<pair<ll, ll>>result;
ll solve = 0;
void dfs() {
	if (result.size() == n) {
		ll sum = 0;
		sum += Map[result[0].first][result[0].second];
		for (int i = 1; i < n; i++) {
			if (result[i].second == result[i - 1].second) {
				sum += (Map[result[i].first][result[i].second] / 2);
			}
			else {
				sum += Map[result[i].first][result[i].second];
			}
		}
		if (sum >= m) {
			solve++;
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			result.push_back({ i, j });
			dfs();
			result.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> Map[i][j];
		}
	}
	dfs();
	cout << solve;
	return 0;
}