#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<ll>sum(n + 1);
	sum[1] = v[0];
	for (int i = 2; i <= n; i++) {
		sum[i] = sum[i - 1] + v[i - 1];
	}
	int m = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		cout << sum[end] - sum[start - 1] << '\n';
	}
	return 0;
}