#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		v[i] -= m;
	}
	vector<ll>sum(n + 1);
	sum[1] = v[1];
	for (int i = 2; i <= n; i++) {
		sum[i] = sum[i - 1] + v[i];
	}
	ll result = 0;
	map<ll, ll>Map;
	for (int i = 1; i <= n; i++) {
		if (sum[i] == 0) {
			if (Map.find(0) == Map.end()) {
				Map.insert({ 0, 1 });
			}
			else {
				Map[0]++;
			}
		}
		else {
			if (Map.find(sum[i]) == Map.end()) {
				Map.insert({ sum[i], 0 });
			}
			else {
				Map[sum[i]]++;
			}
		}
		result += Map[sum[i]];
	}
	cout << result;
	return 0;
}