#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Map[1001][1001];
int n = 0, m = 0;
struct info {
	int command;
	ll starty;
	ll startx;
	ll endy;
	ll endx;
	ll weight;
};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
		}
	}
	vector<info>v(m);
	for (int i = 0; i < m - 1; i++) {
		cin >> v[i].command >> v[i].starty >> v[i].startx >> v[i].endy >> v[i].endx >> v[i].weight;
	}
	cin >> v[m - 1].command >> v[m - 1].starty >> v[m - 1].startx >> v[m - 1].endy >> v[m - 1].endx;
	ll sum = 0;
	for (int i = v[m - 1].starty; i <= v[m - 1].endy; i++) {
		for (int j = v[m - 1].startx; j <= v[m - 1].endx; j++) {
			sum += Map[i][j];
		}
	}
	for (int i = 0; i < m - 1; i++) {
		if (v[m - 1].endy >= v[i].starty && v[m - 1].endx >= v[i].startx) {
			ll y = min(v[m - 1].endy, v[i].endy) - max(v[m - 1].starty, v[i].starty);
			ll x = min(v[m - 1].endx, v[i].endx) - max(v[m - 1].startx, v[i].startx);
			if (y >= 0 && x >= 0) {
				sum += ((y + 1) * (x + 1) * v[i].weight);
			}
		}
	}
	cout << sum;
	return 0;
}