#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compare(const string& a, const string& b) {
	return b + a < a + b;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<string>v;
	string num = "";
	while (cin >> num) {
		v.push_back(num);
	}
	sort(v.begin(), v.end(), compare);
	for (auto& i : v) {
		cout << i;
	}
	return 0;
}