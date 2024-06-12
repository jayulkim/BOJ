#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool visited[125];
int graph[125];
string result = "";
int Find[125][125];
char cicle = '\0';
void dfs(int start) {
	if (visited[start]) {
		cicle = (char)start;
		return;
	}
	visited[start] = true;
	result += (char)start;
	dfs(graph[start]);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	ll k = 0;
	cin >> n >> k >> m;
	for (int i = 0; i < n; i++) {
		string str = "";
		cin >> str;
		for (int j = 0; j < str.length() - 1; j++) {
			Find[(int)str[j]][(int)str[j + 1]]++;
		}
	}
	for (int i = 45; i <= 124; i++) {
		int Max = 0;
		int idx = 0;
		for (int j = 45; j <= 124; j++) {
			if (Max < Find[i][j]) {
				Max = Find[i][j];
				idx = j;
			}
		}
		graph[i] = idx;
	}
	dfs(91);
	k--;
	if (cicle == '\0') {
		if (k >= (ll)(result.length() - 1)) {
			for (int i = 0; i < m; i++) {
				cout << '.';
			}
		}
		else {
			for (int i = k; i < k + m; i++) {
				if (i < result.length() - 1) {
					cout << result[i];
				}
				else {
					cout << '.';
				}
			}
		}
	}
	else {
		string startstr = "";
		string ciclestr = "";
		for (int i = 0; i < result.length(); i++) {
			if (result[i] == cicle) {
				for (int j = 0; j < i; j++) {
					startstr += result[j];
				}
				for (int j = i; j < result.length(); j++) {
					ciclestr += result[j];
				}
				break;
			}
		}
		if (k >= (ll)startstr.length()) {
			k -= (ll)startstr.length();
			k %= (ll)ciclestr.length();
			for (int i = k; i < k + m; i++) {
				cout << ciclestr[i % ciclestr.length()];
			}
		}
		else {
			if (k + m - 1 < startstr.length()) {
				for (int i = k; i < k + m; i++) {
					cout << startstr[i];
				}
			}
			else {
				for (int i = k; i < startstr.length(); i++) {
					cout << startstr[i];
				}
				m -= (startstr.length() - k);
				for (int i = 0; i < m; i++) {
					cout << ciclestr[i % ciclestr.length()];
				}
			}
		}
	}
	return 0;
}
