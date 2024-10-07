#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0;
vector<char>v;
vector<char>passward;
bool visited[16];
int temp = -1;
void dfs() {
	if (passward.size() == m) {
		int mo = 0;
		int notmo = 0;
		for (auto& i : passward) {
			if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
				mo++;
			}
			else {
				notmo++;
			}
		}
		if (mo >= 1 && notmo >= 2) {
			for (auto& i : passward) {
				cout << i;
			}
			cout << '\n';
		}
		return;
	}
	for (int i = temp + 1; i < v.size(); i++) {
		if (!visited[i]) {
			passward.push_back(v[i]);
			visited[i] = true;
			temp = i;
			dfs();
			visited[i] = false;
			passward.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	dfs();
	return 0;
}