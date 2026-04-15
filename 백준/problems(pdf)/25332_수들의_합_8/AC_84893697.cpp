#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v[i] -= num;
	}
	vector<ll>sum(n);
	sum[0] = v[0];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + v[i];
	}
	ll result = 0;
	map<ll, ll>Map;
	for (int i = 0; i < n; i++) {
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
				Map.insert({ sum[i], 0});
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