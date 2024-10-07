#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a = "", b = "";
	cin >> a >> b;
	if (a.length() > b.length()) {
		swap(a, b);
	}
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 0; j <= a.length() - i; j++) {
			string temp = "";
			for (int k = j; k < j + i; k++) {
				temp += a[k];
			}
			bool find = false;
			for (int k = 0; k < a.length(); k += i) {
				int idx = 0;
				for (int n = k; n < k + i; n++) {
					if (temp[idx] != a[n]) {
						find = true;
						break;
					}
					else {
						idx++;
					}
				}
				if (find) {
					break;
				}
			}
			for (int k = 0; k < b.length(); k += i) {
				int idx = 0;
				for (int n = k; n < k + i; n++) {
					if (temp[idx] != b[n]) {
						find = true;
						break;
					}
					else {
						idx++;
					}
				}
				if (find) {
					break;
				}
			}
			if (!find) {
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}