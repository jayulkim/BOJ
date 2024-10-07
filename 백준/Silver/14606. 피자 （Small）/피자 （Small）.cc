#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n = 0;
int result = 0;
void bfs() {
	queue<pair<int, int>>q;
	if (n % 2 == 0) {
		q.push({ n / 2, n / 2 });
	}
	else {
		q.push({ n / 2, n / 2 + 1 });
	}
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		result += (temp.first * temp.second);
		if (temp.first > 1 && temp.first % 2 == 0) {
			q.push({ temp.first / 2, temp.first / 2 });
		}
		else if (temp.first > 1 && temp.first % 2 == 1) {
			q.push({ temp.first / 2, temp.first / 2 + 1 });
		}
		if (temp.second > 1 && temp.second % 2 == 0) {
			q.push({ temp.second / 2, temp.second / 2 });
		}
		else if (temp.second > 1 && temp.second % 2 == 1) {
			q.push({ temp.second / 2, temp.second / 2 + 1 });
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	bfs();
	cout << result;
	return 0;
}