#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Map[4][22] = {
	{ 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0 },
	{ 0, 13, 16, 19, 25, 30, 35, 40, 0 },
	{ 0, 22, 24, 25, 30, 35, 40, 0 },
	{ 0, 28, 27, 26, 25, 30, 35, 40, 0 },
};
vector<ll>v;
vector<ll>graph;
ll result = 0;
bool start[4];
bool change[4];
bool finish[4];
pair<ll, ll>gps[4];
void dfs() {
	if (graph.size() == 10) {
		ll temp = 0;
		memset(start, false, sizeof(start));
		memset(change, false, sizeof(change));
		memset(finish, false, sizeof(finish));
		for (int i = 0; i < 4; i++) {
			gps[i].first = 0;
			gps[i].second = 0;
		}
		for (int i = 0; i < 10; i++) {
			start[graph[i]] = true;
			if (finish[graph[i]]) {
				return;
			}
			if (gps[graph[i]].second % 5 == 0 && gps[graph[i]].second / 5 < 4 && !change[graph[i]] && gps[graph[i]].second / 5 > 0) {
				gps[graph[i]].first = gps[graph[i]].second / 5;
				gps[graph[i]].second = 0;
				change[graph[i]] = true;
			}
			if (!gps[graph[i]].first) {
				gps[graph[i]].second += v[i];
				if (gps[graph[i]].second >= 21) {
					gps[graph[i]].second = 21;
					finish[graph[i]] = true;
				}
				else {
					temp += Map[gps[graph[i]].first][gps[graph[i]].second];
				}
			}
			else if (gps[graph[i]].first == 1 || gps[graph[i]].first == 3) {
				gps[graph[i]].second += v[i];
				if (gps[graph[i]].second >= 8) {
					gps[graph[i]].second = 8;
					finish[graph[i]] = true;
				}
				else {
					temp += Map[gps[graph[i]].first][gps[graph[i]].second];
				}
			}
			else if (gps[graph[i]].first == 2) {
				gps[graph[i]].second += v[i];
				if (gps[graph[i]].second >= 7) {
					gps[graph[i]].second = 7;
					finish[graph[i]] = true;
				}
				else {
					temp += Map[gps[graph[i]].first][gps[graph[i]].second];
				}
			}
			for (int j = 0; j < 4; j++) {
				if (j != graph[i] && !finish[j] && start[j]) {
					if (Map[gps[graph[i]].first][gps[graph[i]].second] != 40 && Map[gps[graph[i]].first][gps[graph[i]].second] != 25 && Map[gps[graph[i]].first][gps[graph[i]].second] != 30 && Map[gps[graph[i]].first][gps[graph[i]].second] != 35) {
						if (gps[graph[i]].first == gps[j].first && Map[gps[graph[i]].first][gps[graph[i]].second] == Map[gps[j].first][gps[j].second]) {
							return;
						}
					}
					else if (Map[gps[graph[i]].first][gps[graph[i]].second] != 30) {
						if (Map[gps[graph[i]].first][gps[graph[i]].second] == Map[gps[j].first][gps[j].second]) {
							return;
						}
					}
					else {
						if (gps[graph[i]].first != 0 && gps[j].first != 0 && Map[gps[graph[i]].first][gps[graph[i]].second] == Map[gps[j].first][gps[j].second]) {
							return;
						}
					}
				}
			}
		}
		result = max(result, temp);
		return;
	}
	for (int i = 0; i < 4; i++) {
		graph.push_back(i);
		dfs();
		graph.pop_back();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 10; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	dfs();
	cout << result;
	return 0;
}