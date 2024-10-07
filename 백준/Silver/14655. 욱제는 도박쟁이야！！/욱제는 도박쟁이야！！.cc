#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	int sum1 = 0, sum2 = 0;
	vector<int>round1(n);
	for (int i = 0; i < n; i++) {
		cin >> round1[i];
	}
	vector<int>round2(n);
	for (int i = 0; i < n; i++) {
		cin >> round2[i];
	}
	for (int i = 0; i < n; i++) {
		if (round1[i] < 0) {
			round1[i] *= -1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (round2[i] > 0) {
			round2[i] *= -1;
		}
	}
	for (int i = 0; i < n; i++) {
		sum1 += round1[i];
		sum2 += round2[i];
	}
	cout << sum1 - sum2;
	return 0;
}