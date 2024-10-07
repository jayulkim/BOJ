#include <bits/stdc++.h>
using namespace std;
bool visited[20];
int n = 0, m = 0;
vector<int>v;
vector<int>ary;
int result = 0;
int temp = -1;
void dfs(int d) {
	if (v.size() == d) {
		int sum = 0;
		for (auto& i : v) {
			sum += i;
		}
		if (sum == m) {
			result++;
		}
		return;
	}
	for (int i = temp + 1; i < ary.size(); i++) {
		if (!visited[i]) {
			v.push_back(ary[i]);
			visited[i] = true;
			temp = i;
			dfs(d);
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
	for (int i = 1; i <= n; i++) {
		dfs(i);
		temp = -1;
	}
	cout << result;
	return 0;
}