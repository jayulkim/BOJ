#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<vector<ll>>v;
void bfs() {
	queue<pair<ll, vector<ll>>>q;
	q.push({ 0, {} });
	while (!q.empty()) {
		pair<ll, vector<ll>> temp = q.front();
		q.pop();
		if (temp.first == n) {
			v.push_back(temp.second);
		}
		if (temp.first + 1 <= n) {
			vector<ll>vv = temp.second;
			vv.push_back(1);
			q.push({ temp.first + 1, vv });
		}
		if (temp.first + 2 <= n) {
			vector<ll>vv = temp.second;
			vv.push_back(2);
			q.push({ temp.first + 2, vv });
		}
		if (temp.first + 3 <= n) {
			vector<ll>vv = temp.second;
			vv.push_back(3);
			q.push({ temp.first + 3, vv });
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bfs();
	sort(v.begin(), v.end());
	if (v.size() < m) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < v[m - 1].size(); i++) {
		if (i == v[m - 1].size() - 1) {
			cout << v[m - 1][i];
		}
		else {
			cout << v[m - 1][i] << '+';
		}
	}
	return 0;
}