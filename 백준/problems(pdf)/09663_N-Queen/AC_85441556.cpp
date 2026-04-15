#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0;
vector<pll>queens;
ll result = 0;
void dfs(ll temp) {
	if (temp == n) {
		result++;
		return;
	}
	for (int i = 0; i < n; i++) {
		bool find = false;
		for (auto& [a, b] : queens) {
			if (llabs(a - temp) == llabs(b - i) || b == i) {
				find = true;
				break;
			}
		}
		if (!find) {
			queens.push_back({ temp, i });
			dfs(temp + 1);
			queens.pop_back();
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