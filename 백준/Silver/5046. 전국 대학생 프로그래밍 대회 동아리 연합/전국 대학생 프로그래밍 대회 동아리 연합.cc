#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, k = 0, h = 0;
	cin >> n >> m >> k >> h;
	int Min = 500001;
	for (int i = 0; i < k; i++) {
		int cost = 0;
		cin >> cost;
		for (int j = 0; j < h; j++) {
			int num = 0;
			cin >> num;
			if (num >= n) {
				Min = min(Min, cost);
			}
		}
	}
	if (n * Min > m) {
		cout << "stay home";
		return 0;
	}
	cout << n * Min;
	return 0;
}