#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (temp + 1 < v[i]) {
			cout << temp + 1;
			return 0;
		}
		temp += v[i];
	}
	cout << temp + 1;
	return 0;
}