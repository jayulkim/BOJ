#include <bits/stdc++.h>
using namespace std;
int n = 0;
vector<int>v;
vector<int>result;
bool visited[14];
int temp = -1;
void dfs() {
	if (result.size() == 6) {
		for (auto& i : result) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = temp + 1; i < v.size(); i++) {
		if (!visited[i]) {
			result.push_back(v[i]);
			visited[i] = true;
			temp = i;
			dfs();
			visited[i] = false;
			result.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			int num = 0;
			cin >> num;
			v.push_back(num);
		}
		dfs();
		temp = -1;
		cout << '\n';
		memset(visited, false, sizeof(visited));
		vector<int>().swap(v);
	}
	return 0;
}