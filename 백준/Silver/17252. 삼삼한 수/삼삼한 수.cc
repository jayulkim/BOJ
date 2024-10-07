#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	if (n == 0 || n == 2) {
		cout << "NO";
		return 0;
	}
	while (n > 0) {
		if (n % 3 == 2) {
			cout << "NO";
			return 0;
		}
		n /= 3;
	}
	cout << "YES";
	return 0;
}