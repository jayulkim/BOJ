#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
char Map[3001][3001];
vector<pair<ll, bool>>x[3001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 'X') {
				x[j].push_back({ i, true });
			}
			else if (Map[i][j] == '#') {
				x[j].push_back({ i, false });
			}
		}
	}
	for (int i = 0; i < m; i++) {
		sort(x[i].begin(), x[i].end());
	}
	ll Min = 987654321;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < x[i].size() - 1; j++) {
			if (x[i][j].second && !x[i][j + 1].second) {
				Min = min(Min, x[i][j + 1].first - x[i][j].first - 1);
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (Map[i][j] == 'X') {
				Map[i][j] = '.';
				Map[i + Min][j] = 'X';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << Map[i][j];
		}
		cout << '\n';
	}
	return 0;
}