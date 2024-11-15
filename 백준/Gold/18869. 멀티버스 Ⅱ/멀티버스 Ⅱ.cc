#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
bool compare(const ll& a, const ll& b) {
	if (a == b) {
		return 0;
	}
	else if (a > b) {
		return 1;
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pll>>Map(n + 1);
	vector<vector<ll>>compareMap(n + 1, vector<ll>(m + 1));
	for (int i = 0; i < n; i++) {
		vector<pll>v;
		for (int j = 0; j < m; j++) {
			cin >> compareMap[i][j];
			v.push_back({ compareMap[i][j], j });
		}
		sort(v.begin(), v.end());
		Map[i] = v;
	}
	ll count = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			bool Find = false;
			for (int k = 0; k < m; k++) {
				if (Map[i][k].second != Map[j][k].second) {
					Find = true;
					break;
				}
				else if (k) {
					if (compare(compareMap[i][k - 1], compareMap[i][k]) != compare(compareMap[j][k - 1], compareMap[j][k])) {
						Find = true;
						break;
					}
				}
			}
			if (!Find) {
				count++;
			}
		}
	}
	cout << count;
	return 0;
}