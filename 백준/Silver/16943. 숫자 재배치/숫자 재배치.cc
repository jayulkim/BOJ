// 옛날 코드
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0;
string str = "";
string result = "";
bool visited[11];
ll Max = 0;
bool Find = false;
void dfs() {
	if (result.length() == str.length()) {
		if (result.back() != '0') {
			string temp = result;
			reverse(temp.begin(), temp.end());
			if (stoll(temp) < n) {
				Max = max(stoll(temp), Max);
				Find = true;
			}
		}
		return;
	}
	for (int i = 0; i < str.length(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			result.push_back(str[i]);
			dfs();
			visited[i] = false;
			result.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str >> n;
	dfs();
	if (!Find) {
		cout << -1;
	}
	else {
		cout << Max;
	}
	return 0;
}