#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n = 0, result = 0, Max = 0;
vector<ll>v;
bool Find = false;
void dfs(ll start) {
	if (result > n - 1 || start >= (1ll << 60)) {
		Find = true;
		return;
	}
	result++;
	if (!binary_search(v.begin(), v.end(), start * 2)) {
		dfs(start * 2);
	}
	if (!binary_search(v.begin(), v.end(), start * 2 + 1)) {
		dfs(start * 2 + 1);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	bool find = false;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		Max = max(Max, num);
		if (num == 1) {
			find = true;
		}
		v.push_back(num);
	}
	if (find) {
		cout << 0;
	}
	else {
		dfs(1);
		if (Find) {
			cout << -1;
		}
		else {
			cout << result;
		}
	}
	return 0;
}