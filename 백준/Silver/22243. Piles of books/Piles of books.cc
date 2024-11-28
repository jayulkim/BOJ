#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
ll Map[51][51];
bool visited[51][51];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
		}
	}
	ll count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Map[i][j]) {
				bool find = false;
				for (int k = i + 1; k < n; k++) {
					if (Map[k][j] >= Map[i][j]) {
						find = true;
						break;
					}
				}
				if (!find) {
					visited[i][j] = true;
				}
				find = false;
				for (int k = i - 1; k >= 0; k--) {
					if (Map[k][j] >= Map[i][j]) {
						find = true;
						break;
					}
				}
				if (!find) {
					visited[i][j] = true;
				}
				find = false;
				for (int k = j + 1; k < n; k++) {
					if (Map[i][k] >= Map[i][j]) {
						find = true;
						break;
					}
				}
				if (!find) {
					visited[i][j] = true;
				}
				find = false;
				for (int k = j - 1; k >= 0; k--) {
					if (Map[i][k] >= Map[i][j]) {
						find = true;
						break;
					}
				}
				if (!find) {
					visited[i][j] = true;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) {
				count++;
			}
		}
	}
	cout << count;
	return 0;
}