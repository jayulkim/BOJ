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
		vector<char>v;
		for (auto& i : str) {
			v.push_back(i);
		}
		bool count = false;
		for (int i = 0; i < str.length() - 1; i++) {
			if (str[i] < str[i + 1]) {
				count = true;
				break;
			}
		}
		if (count) {
			next_permutation(v.begin(), v.end());
		}
		for (auto& i : v) {
			cout << i;
		}
		cout << '\n';
	}
	return 0;
}