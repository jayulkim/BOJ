#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tp;
ll n = 0, m = 0;
bool visited[500001][2];
void bfs(ll start) {
	queue<tp>q;
	q.push({ start, 0, m });
	visited[start][0] = true;
	ll count = 1;
	while (!q.empty()) {
		auto [a, b, c] = q.front();
		q.pop();
		if (visited[m + (b * (b + 1) / 2)][b % 2]) {
			cout << b;
			return;
		}
		visited[a][b % 2] = true;
		if (m + ((b + 1) * (b + 2) / 2) <= 500000 && a - 1 >= 0 && !visited[a - 1][(b + 1) % 2]) {
			visited[a - 1][(b + 1) % 2] = true;
			q.push({ a - 1, b + 1, m + ((b + 1) * (b + 2) / 2) });
		}
		if (m + ((b + 1) * (b + 2) / 2) <= 500000 && a + 1 <= 500000 && !visited[a + 1][(b + 1) % 2]) {
			visited[a + 1][(b + 1) % 2] = true;
			q.push({ a + 1, b + 1, m + ((b + 1) * (b + 2) / 2) });
		}
		if (m + ((b + 1) * (b + 2) / 2) <= 500000 && a * 2 <= 500000 && !visited[a * 2][(b + 1) % 2]) {
			visited[a * 2][(b + 1) % 2] = true;
			q.push({ a * 2, b + 1, m + ((b + 1) * (b + 2) / 2) });
		}
	}
	cout << -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bfs(n);
	return 0;
}