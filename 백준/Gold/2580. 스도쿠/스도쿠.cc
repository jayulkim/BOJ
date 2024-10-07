#include <bits/stdc++.h>
using namespace std;
int Map[10][10];
vector<pair<int, int>>v;
bool Find = false;
void dfs(int n) {
	if (Find) {
		return;
	}
	if (n == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << Map[i][j] << ' ';
			}
			cout << '\n';
		}
		Find = true;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		Map[v[n].first][v[n].second] = i;
		int temp[10];
		bool find = false;
		memset(temp, 0, sizeof(temp));
		for (int j = 0; j < 9; j++) {
			temp[Map[v[n].first][j]]++;
		}
		for (int j = 1; j <= 9; j++) {
			if (temp[j] >= 2) {
				find = true;
				break;
			}
		}
		memset(temp, 0, sizeof(temp));
		for (int j = 0; j < 9; j++) {
			temp[Map[j][v[n].second]]++;
		}
		for (int j = 1; j <= 9; j++) {
			if (temp[j] >= 2) {
				find = true;
				break;
			}
		}
		memset(temp, 0, sizeof(temp));
		for (int j = 3 * (v[n].first / 3); j < 3 * (v[n].first / 3) + 3; j++) {
			for (int k = 3 * (v[n].second / 3); k < 3 * (v[n].second / 3) + 3; k++) {
				temp[Map[j][k]]++;
			}
		}
		for (int j = 1; j <= 9; j++) {
			if (temp[j] >= 2) {
				find = true;
				break;
			}
		}
		memset(temp, 0, sizeof(temp));
		if (!find) {
			dfs(n + 1);
		}
	}
	Map[v[n].first][v[n].second] = 0;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 0) {
				v.push_back({ i, j });
			}
		}
	}
	
	dfs(0);
	return 0;
}