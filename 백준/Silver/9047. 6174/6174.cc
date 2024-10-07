#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		string str = "";
		cin >> str;
		int count = 0;
		while (str != "6174") {
			sort(str.begin(), str.end());
			int a = stoi(str);
			reverse(str.begin(), str.end());
			int b = stoi(str);
			str = to_string(b - a);
			while (str.length() < 4) {
				str += '0';
			}
			count++;
		}
		cout << count << '\n';
	}
	return 0;
}