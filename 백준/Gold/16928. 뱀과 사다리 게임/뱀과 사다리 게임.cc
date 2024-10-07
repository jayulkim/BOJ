#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
ll jump[101];
ll snake[101];
bool visited[101];
ll Forward[6] = { 1, 2, 3, 4, 5, 6 };
void bfs(ll start) {
	visited[start] = true;
	queue<pair<ll, ll>>q;
	q.push({ start, 0 });
	while (!q.empty()) {
		pair<ll, ll> temp = q.front();
		q.pop();
		if (temp.first == 100) {
			cout << temp.second;
			return;
		}
		visited[temp.first] = true;
		for (int i = 0; i < 6; i++) {
			ll dx = temp.first + Forward[i];
			if (dx <= 100 && !visited[dx]) {
				if (jump[dx]) {
					visited[jump[dx]] = true;
					q.push({ jump[dx], temp.second + 1 });
				}
				else if (snake[dx]) {
					visited[snake[dx]] = true;
					q.push({ snake[dx], temp.second + 1 });
				}
				else {
					visited[dx] = true;
					q.push({ dx, temp.second + 1 });
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		jump[start] = end;
	}
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		snake[start] = end;
	}
	bfs(1);
	return 0;
}