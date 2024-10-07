#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num = 0;
		cin >> num;
		if (i % 2 != num % 2) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}