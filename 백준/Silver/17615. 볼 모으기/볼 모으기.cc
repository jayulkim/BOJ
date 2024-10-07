#include <bits/stdc++.h>
using namespace std;
int n = 0;
int Min = 987654321;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	string str = "";
	cin >> str;
	int result = 0;
	bool diff = false;
	for (int i = n - 1; i >= 0; i--) {
		if (str[i] == 'R') {
			if (diff) {
				result++;
			}
		}
		else if (str[i] == 'B') {
			diff = true;
		}
	}
	Min = min(Min, result);
	result = 0;
	diff = false;
	for (int i = n - 1; i >= 0; i--) {
		if (str[i] == 'B') {
			if (diff) {
				result++;
			}
		}
		else if (str[i] == 'R') {
			diff = true;
		}
	}
	Min = min(Min, result);
	result = 0;
	diff = false;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'R') {
			if (diff) {
				result++;
			}
		}
		else if (str[i] == 'B') {
			diff = true;
		}
	}
	Min = min(Min, result);
	result = 0;
	diff = false;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'B') {
			if (diff) {
				result++;
			}
		}
		else if (str[i] == 'R') {
			diff = true;
		}
	}
	Min = min(Min, result);
	cout << Min;
	return 0;
}