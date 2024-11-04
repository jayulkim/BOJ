#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0;
char Map[101][1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	if (m % 2) {
		for (int i = 1; i < n - 1; i++) {
			if (Map[i][m / 2] == 'X') {
				Map[i][m / 2] = 'Y';
			}
			else {
				cout << "NO";
				return 0;
			}
		}
		bool find = false;
		for (int i = 1; i < n - 1; i++) {
			if (m / 2 - 1 >= 0 && m / 2 + 1 < m && Map[i][m / 2 - 1] == 'X' && Map[i][m / 2 + 1] == 'X') {
				Map[i][m / 2 - 1] = 'W';
				Map[i][m / 2 + 1] = 'W';
				find = true;
				break;
			}
		}
		if (!find) {
			cout << "NO";
			return 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (Map[i][j] == 'X') {
					Map[i][j] = 'B';
				}
			}
		}
		cout << "YES" << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << Map[i][j];
			}
			cout << '\n';
		}
	}
	else {
		for (int i = 1; i < n - 1; i++) {
			if (m / 2 - 1 >= 0 && Map[i][m / 2 - 1] == 'X' && Map[i][m / 2] == 'X') {
				Map[i][m / 2 - 1] = 'Y';
				Map[i][m / 2] = 'Y';
			}
			else {
				cout << "NO";
				return 0;
			}
		}
		bool find = false;
		for (int i = 1; i < n - 1; i++) {
			if (m / 2 - 2 >= 0 && m / 2 + 1 < m && Map[i][m / 2 - 2] == 'X' && Map[i][m / 2 + 1] == 'X') {
				Map[i][m / 2 - 2] = 'W';
				Map[i][m / 2 + 1] = 'W';
				find = true;
				break;
			}
		}
		if (!find) {
			cout << "NO";
			return 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (Map[i][j] == 'X') {
					Map[i][j] = 'B';
				}
			}
		}
		cout << "YES" << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << Map[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}