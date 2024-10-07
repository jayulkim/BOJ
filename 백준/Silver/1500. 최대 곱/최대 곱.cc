#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll result = 1;
	vector<ll>v;
	ll sum = 0;
	for (int i = 0; i < m; i++) {
		v.push_back(n / m);
		sum += (n / m);
	}
	int idx = 0;
	while (sum < n) {
		v[idx]++;
		idx++;
		sum++;
	}
	for (auto& i : v) {
		result *= i;
	}
	cout << result;
	return 0;
}