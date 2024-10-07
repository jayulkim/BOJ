#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str = "";
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			cout << (char)tolower(str[j]);
		}
		cout << '\n';
	}
	return 0;
}