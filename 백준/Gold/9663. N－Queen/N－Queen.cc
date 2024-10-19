#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
bool visited[16][16];
ll n = 0;
ll Forward[3][2] = { {-1, -1}, {-1, 0}, {-1, 1} };
vector<pll>queens;
bool bfs(ll y, ll x) {
	for (auto& [a, b] : queens) {
		if (llabs(a - y) == llabs(b - x) || b == x) {
			return false;
		}
	}
	return true;
}
ll result = 0;
void dfs(ll temp) {
	if (temp == n) {
		result++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (bfs(temp, i)) {
			visited[temp][i] = true;
			queens.push_back({ temp, i });
			dfs(temp + 1);
			queens.pop_back();
			visited[temp][i] = false;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dfs(0);
	cout << result;
	return 0;
}