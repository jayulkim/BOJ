#include <bits/stdc++.h>
using namespace std;
int ary[500001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int count = 1;
	ary[1] = 1;
	for (int i = 2; i <= 500000; i++) {
		if (i % 2 == 0) {
			ary[i] = count;
			count++;
		}
		else {
			ary[i] = ary[i - 1];
		}
	}
	int n = 0;
	cin >> n;
	if (n == 1) {
		cout << 1 << '\n';
	}
	else {
		cout << n / 2 << '\n';
	}
	for (int i = 1; i <= n; i++) {
		cout << ary[i] << ' ';
	}
	return 0;
}