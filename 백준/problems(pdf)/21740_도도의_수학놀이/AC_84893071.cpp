#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	return a.first + b.first < b.first + a.first;
}
bool comparell(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.first.length() == b.first.length()) {
		return stoll(a.first) < stoll(b.first);
	}
	return a.first.length() < b.first.length();
}
string rev(string num) {
	string result = "";
	for (int i = num.length() - 1; i >= 0; i--) {
		if (num[i] == '6') {
			result += '9';
		}
		else if (num[i] == '9') {
			result += '6';
		}
		else {
			result += num[i];
		}
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<string>v(n);
	vector<pair<string, int>>reverse;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		reverse.push_back({ rev(v[i]), i });
	}
	sort(reverse.begin(), reverse.end(), comparell);
	reverse.push_back(reverse[n - 1]);
	sort(reverse.begin(), reverse.end(), compare);
	for (auto& i : reverse) {
		cout << v[i.second];
	}
	return 0;
}