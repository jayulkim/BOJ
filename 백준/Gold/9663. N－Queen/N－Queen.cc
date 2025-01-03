#include <bits/stdc++.h>
using namespace std;
int n = 0;
bool up[15], a[30], b[30];
int result = 0;
void dfs(int temp) {
	if (temp == n) {
		result++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (up[i] + a[i + temp] + b[n - i + temp] == 0) {
			up[i] = a[i + temp] = b[n - i + temp] = true;
			dfs(temp + 1);
			up[i] = a[i + temp] = b[n - i + temp] = false;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dfs(0);
	cout << result;
	return 0;
}