#include <bits/stdc++.h>
using namespace std;
void NimSum(int b, int x, int y) {
	vector<int>xx;
	vector<int>yy;
	while (x > 0) {
		xx.push_back(x % b);
		x /= b;
	}
	while (y > 0) {
		yy.push_back(y % b);
		y /= b;
	}
	int result = 0;
	if (xx.size() < yy.size()) {
		for (int i = 0; i < xx.size(); i++) {
			yy[i] += xx[i];
			yy[i] %= b;
		}
		for (int i = 0; i < yy.size(); i++) {
			result += yy[i] * pow(b, i);
		}
		cout << result << '\n';
	}
	else {
		for (int i = 0; i < yy.size(); i++) {
			xx[i] += yy[i];
			xx[i] %= b;
		}
		for (int i = 0; i < xx.size(); i++) {
			result += xx[i] * pow(b, i);
		}
		cout << result << '\n';
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		int b = 0, x = 0, y = 0;
		cin >> b >> x >> y;
		NimSum(b, x, y);
	}
	return 0;
}