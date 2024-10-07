#include <bits/stdc++.h>
using namespace std;
int n = 0;
int Map[21][21];
int temp = 0;
vector<int>st;
vector<int>lk;
bool visited[21];
bool ary[21];
int Min = 987654321;
void dfs() {
	if (st.size() == n / 2) {
		int start = 0;
		int link = 0;
		for (auto& i : st) {
			ary[i] = true;
		}
		for (int i = 1; i <= n; i++) {
			if (!ary[i]) {
				lk.push_back(i);
			}
			else {
				ary[i] = false;
			}
		}
		for (int i = 0; i < st.size(); i++) {
			for (int j = 0; j < st.size(); j++) {
				start += (Map[st[i]][st[j]], Map[st[j]][st[i]]);
			}
		}
		for (int i = 0; i < lk.size(); i++) {
			for (int j = 0; j < lk.size(); j++) {
				link += (Map[lk[i]][lk[j]], Map[lk[j]][lk[i]]);
			}
		}
		Min = min(Min, abs(start - link));
		vector<int>().swap(lk);
	}
	for (int i = temp + 1; i <= n; i++) {
		if (!visited[i]) {
			st.push_back(i);
			visited[i] = true;
			temp = i;
			dfs();
			visited[i] = false;
			st.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> Map[i][j];
		}
	}
	dfs();
	cout << Min;
	return 0;
}