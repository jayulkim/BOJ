#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int count = 1;
	int startx = 1, starty = 1, startz = 1;
	int endx = 0, endy = 0, endz = 0;
	cin >> endx >> endy >> endz;
	while (1) {
		if (startx == endx && starty == endy && startz == endz) {
			break;
		}
		startx++;
		starty++;
		startz++;
		if (startx > 15) {
			startx = 1;
		}
		if (starty > 28) {
			starty = 1;
		}
		if (startz > 19) {
			startz = 1;
		}
		count++;
	}
	cout << count;
	return 0;
}