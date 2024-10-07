#include <bits/stdc++.h>
using namespace std;
string target = "";
int n = 0, m = 0;
char Map[101][101];
bool check(int y, int x) {
	string temp = "";
	for (int i = x; i < min(m, x + (int)target.length()); i++) {
		temp += Map[y][i];
	}
	if (temp == target) {
		return true;
	}
	temp = "";
	for (int i = y; i < min(n, y + (int)target.length()); i++) {
		temp += Map[i][x];
	}
	if (temp == target) {
		return true;
	}
	temp = "";
	for (int i = x; i > max(0, x - (int)target.length()); i--) {
		temp += Map[y][i];
	}
	if (temp == target) {
		return true;
	}
	temp = "";
	for (int i = y; i > max(0, y - (int)target.length()); i--) {
		temp += Map[i][x];
	}
	if (temp == target) {
		return true;
	}
	temp = "";
	int dy = y, dx = x;
	for (int i = 0; i < target.length(); i++) {
		if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
			temp += Map[dy][dx];
			dy--;
			dx--;
		}
	}
	if (temp == target) {
		return true;
	}
	temp = "";
	dy = y, dx = x;
	for (int i = 0; i < target.length(); i++) {
		if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
			temp += Map[dy][dx];
			dy++;
			dx--;
		}
	}
	if (temp == target) {
		return true;
	}
	temp = "";
	dy = y, dx = x;
	for (int i = 0; i < target.length(); i++) {
		if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
			temp += Map[dy][dx];
			dy--;
			dx++;
		}
	}
	if (temp == target) {
		return true;
	}
	temp = "";
	dy = y, dx = x;
	for (int i = 0; i < target.length(); i++) {
		if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
			temp += Map[dy][dx];
			dy++;
			dx++;
		}
	}
	if (temp == target) {
		return true;
	}
	temp = "";
	dy = y, dx = x;
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> target;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check(i, j)) {
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}