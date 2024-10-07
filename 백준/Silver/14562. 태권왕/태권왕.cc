#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll start = 0, End = 0;
void bfs() {
	queue<pair<pair<ll, ll>, ll>>q;
	q.push({ {start, 0}, End });
	while (!q.empty()) {
		pair<pair<ll, ll>, ll> temp = q.front();
		q.pop();
		if (temp.first.first == temp.second) {
			cout << temp.first.second << '\n';
			return;
		}
		else if (temp.first.first < temp.second) {
			q.push({ { temp.first.first + 1, temp.first.second + 1 }, temp.second });
			q.push({ { temp.first.first * 2, temp.first.second + 1 }, temp.second + 3 });
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> End;
		bfs();
	}
	return 0;
}