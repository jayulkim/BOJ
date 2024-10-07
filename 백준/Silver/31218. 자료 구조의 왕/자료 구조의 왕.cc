#include <bits/stdc++.h>
using namespace std;
int Map[1001][1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	int sum = n * m;
	for (int i = 0; i < k; i++) {
		int dy = 0, dx = 0, y = 0, x = 0, command = 0;
		cin >> command;
		if (command == 1) {
			cin >> dy >> dx >> y >> x;
			while (1) {
				if (Map[y][x] == 1) {
					break;
				}
				Map[y][x] = 1;
				sum--;
				if (y + dy < 1 || y + dy > n || x + dx < 1 || x + dx > m) {
					break;
				}
				y += dy;
				x += dx;
			}
		}
		else if (command == 2) {
			cin >> y >> x;
			cout << Map[y][x] << '\n';
		}
		else if (command == 3) {
			cout << sum << '\n';
		}
	}
	return 0;
}