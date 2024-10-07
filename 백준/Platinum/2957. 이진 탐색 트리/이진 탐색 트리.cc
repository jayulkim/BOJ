#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int, ll>m;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	ll sum = 0;
	m.insert({ 0, -1 });
	m.insert({ n + 1, -1 });
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		auto rightidx = m.upper_bound(num);
		auto leftidx = rightidx;
		leftidx--;
		ll Max = max(rightidx->second, leftidx->second) + 1;
		sum += Max;
		m.insert({ num, Max });
		cout << sum << '\n';
	}
	return 0;
}