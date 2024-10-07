#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compare(const string a, const string b) {
	return a + b > b + a;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<string>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), compare);
	bool find = false;
	for (auto& i : v) {
		if (i != "0") {
			find = true;
		}
	}
	if (!find) {
		cout << 0;
	}
	else {
		for (auto& i : v) {
			cout << i;
		}
	}
	return 0;
}