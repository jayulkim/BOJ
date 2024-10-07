#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int starty = 0, startm = 0, startd = 0;
	int endy = 0, endm = 0, endd = 0;
	cin >> starty >> startm >> startd >> endy >> endm >> endd;
	if (endy - starty > 1000 || (endy - starty == 1000 && (endm > startm || (endm == startm && endd >= startd)))) {
		cout << "gg";
		return 0;
	}
	int count = 0;
	while (1) {
		if (starty == endy && startm == endm && startd == endd) {
			break;
		}
		if (startd == 31 && (startm == 1 || startm == 3 || startm == 5 || startm == 7 || startm == 8 || startm == 10 || startm == 12)) {
			startd = 1;
			startm++;
			if (startm == 13) {
				startm = 1;
				starty++;
			}
			goto day;
		}
		if (startd == 30 && (startm == 4 || startm == 6 || startm == 9 || startm == 11)) {
			startd = 1;
			startm++;
			goto day;
		}
		if ((starty % 4 == 0 && starty % 100 != 0) || starty % 400 == 0) {
			if (startd == 29 && startm == 2) {
				startd = 1;
				startm++;
				goto day;
			}
		}
		else {
			if (startd == 28 && startm == 2) {
				startd = 1;
				startm++;
				goto day;
			}
		}
		startd++;
	day:
		count++;
	}
	cout << "D-" << count;
	return 0;
}