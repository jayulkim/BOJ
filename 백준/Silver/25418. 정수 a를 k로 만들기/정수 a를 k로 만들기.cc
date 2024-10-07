#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
bool visited[1000001];
void bfs() {
	visited[n] = true;
	queue<pair<ll, ll>>q;
	q.push({n, 0});
	while (!q.empty()) {
		pair<ll, ll> temp = q.front();
		q.pop();
		visited[temp.first] = true;
		if (temp.first == m) {
			cout << temp.second;
			return;
		}
		if (temp.first + 1 <= m && !visited[temp.first + 1]) {
			visited[temp.first + 1] = true;
			q.push({ temp.first + 1, temp.second + 1 });
		}
		if (temp.first * 2 <= m && !visited[temp.first * 2]) {
			visited[temp.first * 2] = true;
			q.push({ temp.first * 2, temp.second + 1 });
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bfs();
	return 0;
}