#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll ary[100001];
map<ll, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll command = 0, a = 0, b = 0;
		cin >> command;
		if (command == 1) {
			cin >> a >> b;
			ary[a] |= (1 << b);
		}
		else if (command == 2) {
			cin >> a >> b;
			ary[a] &= ~(1 << b);
		}
		else if (command == 3) {
			cin >> a;
			ary[a] <<= 1;
			ary[a] &= ~(1 << 21);
		}
		else if (command == 4) {
			cin >> a;
			ary[a] >>= 1;
			ary[a] &= ~1;
		}
	}
	ll result = 0;
	for (int i = 1; i <= n; i++) {
		if (!Map[ary[i]]) {
			result++;
			Map[ary[i]]++;
		}
	}
	cout << result;
	return 0;
}