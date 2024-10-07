#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compare(const string& a, const string& b) {
	return b + a > a + b;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<string>v(n);
	vector<string>ary;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i][0] != '0') {
			string temp = v[i];
			vector<string>result;
			for (int j = 0; j < v.size(); j++) {
				if (i != j) {
					result.push_back(v[j]);
				}
			}
			sort(result.begin(), result.end(), compare);
			for (auto& i : result) {
				temp += i;
			}
			ary.push_back(temp);
		}
	}
	if (ary.empty()) {
		cout << "INVALID";
		return 0;
	}
	sort(ary.begin(), ary.end());
	cout << ary[0];
	return 0;
}