#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int count = 1;
	while (1) {
		int n = 0;
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<pair<string, vector<char>>>v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].first;
			for (int j = 0; j < n - 1; j++) {
				char c;
				cin >> c;
				v[i].second.push_back(c);
			}
		}
		cout << "Group " << count << '\n';
		count++;
		int temp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (v[i].second[j] == 'N') {
					temp++;
					cout << v[(i - j - 1 + n) % n].first << " was nasty about " << v[i].first << '\n';
				}
			}
		}
		if (temp == 0) {
			cout << "Nobody was nasty" << '\n';
		}
		cout << '\n';
	}
	return 0;
}