#include <bits/stdc++.h>
using namespace std;
bool ary[100001];
int prime[10001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i * i <= 100000; i++) {
		if (!ary[i]) {
			for (int j = i * i; j <= 100000; j += i) {
				ary[j] = true;
			}
		}
	}
	int next = 0;
	for (int i = 2; i <= 100000; i++) {
		if (!ary[i]) {
			prime[next++] = i;
		}
	}
	int n = 0, m = 0;
	cin >> n >> m;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		int Max = 0;
		int idx = 0;
		if (i == 1) {
			Max = 1;
		}
		else {
			int temp = i;
			while (temp > 1) {
				if (temp % prime[idx] == 0) {
					Max = prime[idx];
					temp /= prime[idx];
				}
				else {
					idx++;
				}
			}
		}
		if (Max <= m) {
			count++;
		}
	}
	cout << count;
	return 0;
}