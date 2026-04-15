#include <bits/stdc++.h>
using namespace std;
int prime[2000001];
int mod[2000001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i * i <= 2000000; i++) {
		if (prime[i] == 0) {
			for (int j = i * i; j <= 2000000; j += i) {
				prime[j] = 1;
			}
		}
	}
	vector<int>v;
	for (int i = 2; i <= 2000000; i++) {
		if (prime[i] == 0) {
			v.push_back(i);
		}
	}
	int n = 0;
	cin >> n;
	vector<int>ary(n);
	for (int i = 0; i < n; i++) {
		cin >> ary[i];
	}
	int Max = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < n; j++) {
			mod[ary[j] % v[i]]++;
			Max = max(Max, mod[ary[j] % v[i]]);
		}
		for (int j = 0; j < n; j++) {
			mod[ary[j] % v[i]]--;
		}
	}
	cout << Max;
	return 0;
}