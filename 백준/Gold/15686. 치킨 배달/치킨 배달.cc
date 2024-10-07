#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0;
vector<pair<int, int>>pos;
vector<pair<int, int>>chi;
bool visited[51][51];
vector<pair<int, int>>choice;
int temp = -1;
int Min = 987654321;
void dfs() {
	if (choice.size() == m) {
		int sum = 0;
		for (int i = 0; i < pos.size(); i++) {
			int dis = 987654321;
			for (int j = 0; j < choice.size(); j++) {
				dis = min(dis, abs(pos[i].first - choice[j].first) + abs(pos[i].second - choice[j].second));
			}
			sum += dis;
		}
		Min = min(Min, sum);
	}
	for (int i = temp + 1; i < chi.size(); i++) {
		if (!visited[chi[i].first][chi[i].second]) {
			choice.push_back({ chi[i].first, chi[i].second });
			visited[chi[i].first][chi[i].second] = true;
			temp = i;
			dfs();
			visited[chi[i].first][chi[i].second] = false;
			choice.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num = 0;
			cin >> num;
			if (num == 1) {
				pos.push_back({ i, j });
			}
			else if (num == 2) {
				chi.push_back({ i, j });
			}
		}
	}
	dfs();
	cout << Min;
	return 0;
}