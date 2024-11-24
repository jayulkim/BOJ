#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<bool>visited(10, false);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ll a = n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		ll num = 0;
		cin >> num;
		visited[num] = true;
	}
	if (m == 10) {
		cout << llabs(100 - n);
		return 0;
	}
	ll Min = LLONG_MAX;
	ll result = -1;
	for (int i = 0; i <= 1000000; i++) {
		ll temp = i;
		bool find = false;
		ll count = 0;
		if (!i) {
			if (!visited[i]) {
				Min = min(Min, llabs(n - i) + 1);
			}
		}
		else {
			while (temp > 0) {
				if (visited[temp % 10]) {
					find = true;
				}
				count++;
				temp /= 10;
			}
			if (!find) {
				Min = min(Min, llabs(n - i) + count);
			}
		}
	}
	cout << min(Min, llabs(100 - n));
	return 0;
}