#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;
ll Map[101][101];
ll dp[101];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	ll sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			dp[j] += Map[j][i];
			if (dp[j] >= k) {
				cout << j + 1 << ' ' << i + 1;
				return 0;
			}
		}
	}
	return 0;
}