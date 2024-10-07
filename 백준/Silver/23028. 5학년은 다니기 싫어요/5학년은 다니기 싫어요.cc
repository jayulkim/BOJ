#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<pair<int, int>>v(10);
	for (int i = 0; i < 10; i++) {
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 0; i < 10; i++) {
		int idx = 0;
		if (m >= 66 && k >= 130 && n <= 8) {
			cout << "Nice";
			return 0;
		}
		while (v[i].first--) {
			if (idx == 6) {
				break;
			}
			m += 3;
			k += 3;
			idx++;
		}
		while (v[i].second--) {
			if (idx == 6) {
				break;
			}
			k += 3;
			idx++;
		}
		n++;
	}
	cout << "Nae ga wae";
	return 0;
}