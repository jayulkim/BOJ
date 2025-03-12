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
ll Map[11][11];
bool a[22];
vector<pll>v[22];
vector<pll>graph[22];
ll idx = 0;
ll Max = 0;
void bfs(ll y, ll x) {
	queue<pll>q;
	q.push({ y, x });
	while (!q.empty()) {
		pll temp = q.front();
		q.pop();
		v[idx].push_back({ temp.first, temp.second });
		if (temp.first + 1 < n && temp.second - 1 >= 0) {
			q.push({ temp.first + 1, temp.second - 1 });
		}
	}
	idx++;
}
void dfs(ll idx, ll count, ll size) {
	if (idx == size) {
		Max = max(Max, count);
		return;
	}
	bool find = false;
	for (auto& i : graph[idx]) {
		if (!a[n - i.first + i.second]) {
			a[n - i.first + i.second] = true;
			find = true;
			dfs(idx + 1, count + 1, size);
			a[n - i.first + i.second] = false;
		}
	}
	if (!find) {
		dfs(idx + 1, count, size);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		bfs(0, i);
	}
	for (int i = 1; i < n; i++) {
		bfs(i, n - 1);
	}
	for (int i = 0; i < idx; i++) {
		for (auto& j : v[i]) {
			if (Map[j.first][j.second]) {
				graph[i].push_back({ j.first, j.second });
			}
		}
	}
	dfs(0, 0, idx);
	cout << Max;
	return 0;
}