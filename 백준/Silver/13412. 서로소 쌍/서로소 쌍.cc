#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
	int temp = x % y;
	while (temp > 0) {
		x = y;
		y = temp;
		temp = x % y;
	}
	return y;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		int n = 0;
		cin >> n;
		if (n == 1) {
			cout << 1 << '\n';
		}
		else {
			vector<int>v;
			for (int i = 1; i * i <= n; i++) {
				if (i * i == n && n % i == 0) {
					v.push_back(i);
				}
				else if (n % i == 0) {
					v.push_back(i);
					v.push_back(n / i);
				}
			}
			sort(v.begin(), v.end());
			int count = 0;
			for (int i = 0; i < v.size() / 2; i++) {
				if (gcd(v[i], v[v.size() - 1 - i]) == 1) {
					count++;
				}
			}
			cout << count << '\n';
			vector<int>().swap(v);
		}
	}
	return 0;
}