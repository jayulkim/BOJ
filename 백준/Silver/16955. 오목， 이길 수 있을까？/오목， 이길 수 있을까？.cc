#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char Map[11][11];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (Map[i][j] == 'X') {
				bool find = false;
				ll count = 0;
				for (int k = j; k >= max(0, j - 4); k--) {
					if (Map[i][k] == 'X') {
						count++;
					}
					else if (!find && Map[i][k] == '.') {
						count++;
						find = true;
					}
					else {
						break;
					}
				}
				if (count >= 5) {
					cout << 1;
					return 0;
				}
				find = false;
				count = 0;
				for (int k = i; k >= max(0, i - 4); k--) {
					if (Map[k][j] == 'X') {
						count++;
					}
					else if (!find && Map[k][j] == '.') {
						count++;
						find = true;
					}
					else {
						break;
					}
				}
				if (count >= 5) {
					cout << 1;
					return 0;
				}
				find = false;
				count = 0;
				for (int k = i; k < min(10, i + 5); k++) {
					if (Map[k][j] == 'X') {
						count++;
					}
					else if (!find && Map[k][j] == '.') {
						count++;
						find = true;
					}
					else {
						break;
					}
				}
				if (count >= 5) {
					cout << 1;
					return 0;
				}
				find = false;
				count = 0;
				for (int k = j; k < min(10, j + 5); k++) {
					if (Map[i][k] == 'X') {
						count++;
					}
					else if (!find && Map[i][k] == '.') {
						find = true;
						count++;
					}
					else {
						break;
					}
				}
				if (count >= 5) {
					cout << 1;
					return 0;
				}
				find = false;
				count = 0;
				for (int k = 0; k < 10; k++) {
					ll dy = i - k;
					ll dx = j - k;
					if (dy >= 0 && dy < 10 && dx >= 0 && dx < 10) {
						if (Map[dy][dx] == 'X') {
							count++;
						}
						else if (!find && Map[dy][dx] == '.') {
							count++;
							find = true;
						}
						else {
							break;
						}
					}
					else {
						break;
					}
				}
				if (count >= 5) {
					cout << 1;
					return 0;
				}
				find = false;
				count = 0;
				for (int k = 0; k < 10; k++) {
					ll dy = i + k;
					ll dx = j + k;
					if (dy >= 0 && dy < 10 && dx >= 0 && dx < 10) {
						if (Map[dy][dx] == 'X') {
							count++;
						}
						else if (!find && Map[dy][dx] == '.') {
							count++;
							find = true;
						}
						else {
							break;
						}
					}
					else {
						break;
					}
				}
				if (count >= 5) {
					cout << 1;
					return 0;
				}
				find = false;
				count = 0;
				for (int k = 0; k < 10; k++) {
					ll dy = i - k;
					ll dx = j + k;
					if (dy >= 0 && dy < 10 && dx >= 0 && dx < 10) {
						if (Map[dy][dx] == 'X') {
							count++;
						}
						else if (!find && Map[dy][dx] == '.') {
							count++;
							find = true;
						}
						else {
							break;
						}
					}
					else {
						break;
					}
				}
				if (count >= 5) {
					cout << 1;
					return 0;
				}
				find = false;
				count = 0;
				for (int k = 0; k < 10; k++) {
					ll dy = i + k;
					ll dx = j - k;
					if (dy >= 0 && dy < 10 && dx >= 0 && dx < 10) {
						if (Map[dy][dx] == 'X') {
							count++;
						}
						else if (!find && Map[dy][dx] == '.') {
							count++;
							find = true;
						}
						else {
							break;
						}
					}
					else {
						break;
					}
				}
				if (count >= 5) {
					cout << 1;
					return 0;
				}
			}
		}
	}
	cout << 0;
	return 0;
}