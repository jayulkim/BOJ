#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld comb(ld x, ld y) {
	ld result = 1;
	while (y--) {
		result *= x;
		result /= (y + 1);
		x--;
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<ld>v(n);
	ld sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	ld k = 0;
	cin >> k;
	ld result = 0;
	for (int i = 0; i < n; i++) {
		if (comb(v[i], k) > 0) {
			result += comb(v[i], k);
		}
	}
	cout << fixed;
	cout.precision(50);
	cout << result / comb(sum, k);
	return 0;
}