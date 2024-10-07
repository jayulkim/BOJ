#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	while (n != 0) {
		if (n < 0) {
			if (-n % 2 == 1) {
				v.push_back(1);
				n = -((n - 1) / 2);
			}
			else {
				v.push_back(0);
				n = -(n / 2);
			}
		}
		else {
			if (n % 2 == 1) {
				v.push_back(1);
				n = -((n - 1) / 2);
			}
			else {
				v.push_back(0);
				n = -(n / 2);
			}
		}
	}
	reverse(v.begin(), v.end());
	for (auto& i : v) {
		cout << i;
	}
	return 0;
}