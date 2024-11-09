#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll visited[10][200001];
ll sum[10][200001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v(n + 1);
	ll count = 0;
	for (int i = 1; i <= n; i++) {
		ll num = 0;
		cin >> num;
		visited[num][i] = 1;
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = sum[i][j - 1] + visited[i][j];
		}
	}
	ll start = 0, end = 1;
	ll Max = 0;
	while (end <= n) {
		ll temp = 0;
		for (int i = 1; i <= 9; i++) {
			if (sum[i][end] - sum[i][start]) {
				temp++;
			}
		}
		if (temp > 2) {
			start++;
		}
		else {
			Max = max(Max, end - start);
			end++;
		}
	}
	cout << Max;
	return 0;
}