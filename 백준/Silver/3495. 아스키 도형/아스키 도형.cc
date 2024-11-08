#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0;
char Map[101][101];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bool find = false;
	ll count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == '/' || Map[i][j] == '\\') {
				count++;
				if (!find) {
					find = true;
				}
				else {
					find = false;
				}
			}
			else {
				if (find) {
					count += 2;
				}
			}
		}
	}
	cout << count / 2;

	return 0;
}