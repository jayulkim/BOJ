#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if (26 * n < m || n > m) {
		cout << '!';
		return 0;
	}
	string result = "";
	for (int i = 0; i < n; i++) {
		result += 'A';
	}
	m -= n;
	ll idx = 0;
	for (int i = n - 1; i >= 0 && m - 25 >= 0; i--) {
		result[i] = 'Z';
		m -= 25;
		idx = i;
	}
	if (m) {
		result[idx - 1] = 'A' + m;
	}
	cout << result;
	return 0;
}