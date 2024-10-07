#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> ti;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	ll result = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			result += 3;
		}
		else if (i < n - 1) {
			result += 4;
		}
		else {
			result += 2;
		}
	}
	result *= (m - 1);
	result += (n - 1);
	cout << result;
	return 0;
}