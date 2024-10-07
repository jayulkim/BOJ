#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	int Max = n, Min = 1, count = 0;;
	while (1) {
		cout << Max << ' ';
		count++;
		Max--;
		if (count == n) {
			break;
		}
		cout << Min << ' ';
		count++;
		Min++;
		if (count == n) {
			break;
		}
	}
	return 0;
}