#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	map<string, int>m;
	int count = 0;
	for (int i = 0; i < n; i++) {
		string str = "";
		cin >> str;
		string temp = "";
		if (str == "Cheese") {
			if (m.find(str) == m.end()) {
				m[str]++;
				count++;
			}
		}
		else if (str.length() > 6) {
			for (int j = str.length() - 1; j >= str.length() - 6; j--) {
				temp += str[j];
			}
			if (temp == "eseehC") {
				string x = "";
				for (int j = 0; j < str.length() - 6; j++) {
					x += str[j];
				}
				if (m.find(x) == m.end()) {
					count++;
					m[x]++;
				}
			}
		}
	}
	if (count >= 4) {
		cout << "yummy";
	}
	else {
		cout << "sad";
	}
	return 0;
}