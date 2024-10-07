#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<ll>sum(n);
	sum[0] = v[0];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + v[i];
	}
	ll result = 0;
	map<ll, ll>Map;
	Map[0]++;
	for (int i = 0; i < n; i++) {
		if (Map[sum[i] - m] > 0) {
			result += Map[sum[i] - m];
		}
		Map[sum[i]]++;
	}
	cout << result;
	return 0;
}