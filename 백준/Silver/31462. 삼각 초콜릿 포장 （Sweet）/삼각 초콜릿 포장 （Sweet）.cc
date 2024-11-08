#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0;
char Map[5001][5001];
bool visited[5001][5001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (!visited[i][j]) {
				if (i + 1 < n && j + 1 <= i + 1 && Map[i][j] == 'R' && Map[i + 1][j] == 'R' && Map[i + 1][j + 1] == 'R' && !visited[i + 1][j] && !visited[i + 1][j + 1]) {
					visited[i][j] = visited[i + 1][j] = visited[i + 1][j + 1] = true;
				}
				else if (i + 1 < n && j + 1 <= i + 1 && Map[i][j] == 'B' && Map[i][j + 1] == 'B' && Map[i + 1][j + 1] == 'B' && !visited[i][j + 1] && !visited[i + 1][j + 1]) {
					visited[i][j] = visited[i][j + 1] = visited[i + 1][j + 1] = true;
				}
				else {
					cout << 0;
					return 0;
				}
			}
		}
	}
	cout << 1;
	return 0;
}