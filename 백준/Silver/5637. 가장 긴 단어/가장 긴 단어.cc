#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.first.length() == b.first.length()) {
		return a.second < b.second;
	}
	return a.first.length() > b.first.length();
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	vector<pair<string, int>>v;
	int idx = 0;
	while (1) {
		cin >> str;
		if (str == "E-N-D") {
			break;
		}
		string temp = "";
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '-' || (str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A')) {
				temp += str[i];
			}
			else {
				v.push_back({ temp, idx });
				idx++;
				temp = "";
			}
		}
		if (temp != "\0") {
			v.push_back({ temp, idx });
			idx++;
		}
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v[0].first.length(); i++) {
		v[0].first[i] = tolower(v[0].first[i]);
	}
	cout << v[0].first;
	return 0;
}