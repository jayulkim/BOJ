#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool visited[10];
bool ary[10001];
int n = 0, m = 0;
vector<int>v;
vector<int>result;
vector<int>solve;
int temp = -1;
void dfs() {
	if (result.size() == m) {
		int sum = 0;
		for (auto& i : result) {
			sum += i;
		}
		if (!ary[sum]) {
			solve.push_back(sum);
		}
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
	for (int i = 2; i * i <= 10000; i++) {
		if (!ary[i]) {
			for (int j = i * i; j <= 10000; j += i) {
				ary[j] = true;
			}
		}
	}
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		v.push_back(num);
	}
	dfs();
	if (solve.size() == 0) {
		cout << -1;
		return 0;
	}
	sort(solve.begin(), solve.end());
	solve.erase(unique(solve.begin(), solve.end()), solve.end());
	for (auto& i : solve) {
		cout << i << ' ';
	}
	return 0;
}