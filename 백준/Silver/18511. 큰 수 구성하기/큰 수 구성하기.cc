#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int n = 0, m = 0;
string str = "";
bool Find = false;
void dfs(int size) {
	if (Find) {
		return;
	}
	if (str.length() == size) {
		if (stoi(str) <= n) {
			Find = true;
			cout << stoi(str);
		}
		return;
	}
	for (int i = 0; i < m; i++) {
		str += (char)(v[i] + 48);
		dfs(size);
		str.pop_back();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num = 0;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	dfs(to_string(n).length());
	if (!Find) {
		dfs(to_string(n).length() - 1);
	}
	return 0;
}