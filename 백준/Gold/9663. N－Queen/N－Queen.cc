#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0;
ll up[15], ary[60];
ll result = 0;
void dfs(ll temp) {
	if (temp == n) {
		result++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!up[i] && !ary[i + temp] && !ary[3 * n - i + temp]) {
			up[i]++;
			ary[i + temp]++;
			ary[3 * n - i + temp]++;
			dfs(temp + 1);
			up[i]--;
			ary[i + temp]--;
			ary[3 * n - i + temp]--;
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