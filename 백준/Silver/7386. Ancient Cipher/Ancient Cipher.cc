#include <bits/stdc++.h>
using namespace std;
int up[125];
int down[125];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	string result = "";
	cin >> str >> result;
	for (auto& i : str) {
		up[i]++;
	}
	for (auto& i : result) {
		down[i]++;
	}
	vector<int>a;
	vector<int>b;
	for (int i = 0; i < 125; i++) {
		if (up[i]) {
			a.push_back(up[i]);
		}
		if (down[i]) {
			b.push_back(down[i]);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a == b) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}