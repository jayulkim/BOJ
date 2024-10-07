#include <bits/stdc++.h>
using namespace std;
int Forward[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
char Map[155][155];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	string str = "";
	cin >> str;
	int idx = 0, y = 51, x = 51, starty = 51, startx = 51, endy = 0, endx = 0;
	Map[y][x] = '.';
	for (int i = 0; i < n; i++) {
		if (str[i] == 'R') {
			idx++;
			idx %= 4;
		}
		else if (str[i] == 'L') {
			idx--;
			idx += 4;
			idx %= 4;
		}
		else if (str[i] == 'F') {
			y += Forward[idx][0];
			x += Forward[idx][1];
		}
		starty = min(starty, y);
		startx = min(startx, x);
		endy = max(endy, y);
		endx = max(endx, x);
		Map[y][x] = '.';
	}
	for (int i = starty; i <= endy; i++) {
		for (int j = startx; j <= endx; j++) {
			if (Map[i][j] == '\0') {
				cout << '#';
			}
			else {
				cout << Map[i][j];
			}
		}
		cout << '\n';
	}
	return 0;
}