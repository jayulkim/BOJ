#include <bits/stdc++.h>
using namespace std;
int Map[501][2];
bool visited[501][501];
vector<int>v[501];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	int count = 1;
	while (num--) {
		int n = 0, m = 0, k = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			int h = 0;
			char c;
			cin >> h >> c;
			if (c == 'I') {
				Map[h][0]++;
			}
			else {
				Map[h][1]++;
			}
		}
		for (int i = 0; i < m; i++) {
			int h = 0, t = 0;
			cin >> h >> t;
			v[h].push_back(t);
		}
		for (int i = 1; i <= k; i++) {
			sort(v[i].begin(), v[i].end());
			for (int j = v[i].size() - 1; j >= 0; j--) {
				if (Map[i][1] > 0) {
					v[i][j]--;
					Map[i][1]--;
					visited[i][j] = true;
				}
			}
		}
		for (int i = 1; i <= k; i++) {
			for (int j = v[i].size() - 1; j >= 0; j--) {
				while (visited[i][j] && v[i][j] > 0 && Map[i][0] > 0) {
					Map[i][0]--;
					v[i][j]--;
				}
				while (v[i][j] > 0 && Map[i][1] > 0) {
					Map[i][1]--;
					v[i][j]--;
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= k; i++) {
			sum += Map[i][0];
			sum += Map[i][1];
		}
		cout << "Data Set " << count << ":" << '\n';
		cout << sum << '\n';
		memset(Map, 0, sizeof(Map));
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= k; i++) {
			vector<int>().swap(v[i]);
		}
		count++;
	}
}