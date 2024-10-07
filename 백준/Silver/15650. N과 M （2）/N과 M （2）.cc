#include <bits/stdc++.h>
using namespace std;
bool visited[9];
int n = 0, m = 0;
vector<int>v;
int temp = 0;
void dfs() {
	if (v.size() == m) {
		for (auto& i : v) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = temp + 1; i <= n; i++) {
		if (!visited[i]) {
			v.push_back(i);
			temp = i;
			visited[i] = true;
			dfs();
			visited[i] = false;
			v.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	dfs();
	return 0;
}