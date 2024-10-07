#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
bool visited[100001];
int n = 0, m = 0;
int result = 1000000000;
int solve = 0;
void bfs() {
	visited[n] = true;
	queue<pair<int, int>>q;
	q.push({n, 0});
	while (!q.empty()) {
		int temp = q.front().first;
		int time = q.front().second;
		if (time > result) {
			return;
		}
		if (temp == m) {
			result = time;
			solve++;
		}
		visited[temp] = true;
		q.pop();
		if (temp + 1 <= 100000 && !visited[temp + 1]) {
			q.push({ temp + 1, time + 1 });
		}
		if (temp - 1 >= 0 && !visited[temp - 1]) {
			q.push({ temp - 1, time + 1 });
		}
		if (temp * 2 <= 100000 && !visited[temp * 2]) {
			q.push({ temp * 2, time + 1 });
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bfs();
	cout << result << '\n' << solve;
	return 0;
}