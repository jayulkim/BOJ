#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll>m;
int main(void) {
	int n = 0;
	cin >> n;
	ll sum = 0;
	m.insert({ -1, 0 });
	m.insert({ n, 0 });
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		auto rightidx = m.upper_bound(num);
		auto leftidx = rightidx;
		leftidx--;
		sum += (max(rightidx->second, leftidx->second) + 1);
		m.insert({ num, max(rightidx->second, leftidx->second) + 1 });
	}
	cout << sum;
	return 0;
}