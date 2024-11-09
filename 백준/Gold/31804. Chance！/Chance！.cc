#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tp;
ll n = 0, m = 0;
bool visited[1000001][2];
void bfs(ll start) {
	queue<tp>q;
	visited[start][0] = true;
	q.push({ start, 0, 0 });
	while (!q.empty()) {
		auto [a, b, c] = q.front();
		q.pop();
		visited[a][c] = true;
		if (a == m) {
			cout << b;
			return;
		}
		if (a + 1 <= m && !visited[a + 1][c]) {
			q.push({ a + 1, b + 1, c });
			visited[a + 1][c] = true;
		}
		if (a * 2 <= m && !visited[a * 2][c]) {
			q.push({ a * 2, b + 1, c });
			visited[a * 2][c] = true;
		}
		if (!c && a * 10 <= m && !visited[a * 10][c]) {
			q.push({ a * 10, b + 1, c + 1 });
			visited[a * 10][c] = true;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bfs(n);
	return 0;
}