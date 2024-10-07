#include <bits/stdc++.h>
using namespace std;
bool visited[10001];
int n = 0, m = 0;
vector<int>v;
vector<int>ary;
void dfs() {
	if (v.size() == m) {
		for (auto& i : v) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	for (auto& i : ary) {
		if (!visited[i]) {
			v.push_back(i);
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
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		ary.push_back(num);
	}
	sort(ary.begin(), ary.end());
	dfs();
	return 0;
}