#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	string str = "";
	cin >> str;
	vector<string>v;
	if (n <= 25) {
		cout << str;
		return 0;
	}
	string temp = "";
	for (int i = 0; i < n; i++) {
		if (str[i] == '.') {
			temp += str[i];
			v.push_back(temp);
			temp = "";
			i++;
		}
		temp += str[i];
	}
	string s = "";
	for (int i = 11; i < n - 11; i++) {
		s += str[i];
	}
	for (auto& i : v) {
		if (i.find(s) == -1) {
			int count = 0;
			for (int j = 0; j < n; j++) {
				if (j >= 9 && j < n - 10) {
					if (count == 0) {
						cout << "......";
						count++;
					}
				}
				else {
					cout << str[j];
				}
			}
			return 0;
		}
	}
	int count = 0;
	for (int j = 0; j < n; j++) {
		if (j >= 11 && j < n - 11) {
			if (count < 3) {
				cout << '.';
				count++;
			}
		}
		else {
			cout << str[j];
		}
	}
	return 0;
}