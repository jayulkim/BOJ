#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
bool visited[20001];
void bfs(ll x) {
	visited[1] = true;
	queue<pair<string, ll>>q;
	q.push({ "1", 1 });
	while (!q.empty()) {
		pair<string, ll>temp = q.front();
		q.pop();
		if (temp.second == 0) {
			cout << temp.first << '\n';
			return;
		}
		visited[temp.second] = true;
		if ((temp.second * 10) % x >= 0 && (temp.second * 10) % x < 20000 && !visited[(temp.second * 10) % x]) {
			visited[(temp.second * 10) % x] = true;
			q.push({ temp.first + '0', (temp.second * 10) % x });
		}
		if ((temp.second * 10 + 1) % x >= 0 && (temp.second * 10 + 1) % x < 20000 && !visited[(temp.second * 10 + 1) % x]) {
			visited[(temp.second * 10 + 1) % x] = true;
			q.push({ temp.first + '1', (temp.second * 10 + 1) % x });
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		ll n = 0;
		cin >> n;
		bfs(n);
		memset(visited, false, sizeof(visited));
	}
	return 0;
}