#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct info {
	int start;
	int end;
	ll time;
};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0, temp = 0, Max = 0;
	cin >> n >> m;
	vector<ll>v(n + 1);
	vector<ll>sum(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	sum[1] = v[1];
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + v[i];
	}
	vector<info>ary(m);
	for (int i = 0; i < m; i++) {
		cin >> ary[i].start >> ary[i].end >> ary[i].time;
		temp = sum[ary[i].start - 1];
		if (ary[i].time % sum[n] > temp) {
			temp += (ary[i].time / sum[n] + 1) * sum[n];
		}
		else {
			temp += (ary[i].time / sum[n]) * sum[n];
		}
		if (ary[i].start <= ary[i].end) {
			temp += (sum[ary[i].end - 1] - sum[ary[i].start - 1]);
		}
		else {
			temp += sum[ary[i].end - 1] - sum[ary[i].start - 1] + sum[n];
		}
		Max = max(Max, temp);
	}
	cout << Max;
	return 0;
}