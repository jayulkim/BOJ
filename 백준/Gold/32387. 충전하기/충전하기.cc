#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> ti;
map<ll, ll>v;
ll Map[1000001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		v.insert({ i, i });
	}
	for (int i = 0; i < m; i++) {
		ll command = 0, a = 0;
		cin >> command >> a;
		if (command == 1) {
			if (!Map[a]) {
				Map[a] = i + 1;
				cout << a << '\n';
				v.erase(a);
			}
			else {
				auto idx = v.upper_bound(a);
				if (idx == v.end()) {
					cout << -1 << '\n';
				}
				else {
					Map[idx->second] = i + 1;
					cout << idx->second << '\n';
					v.erase(idx->second);
				}
			}
		}
		else {
			if (Map[a]) {
				cout << Map[a] << '\n';
				v.insert({ a, a });
				Map[a] = 0;
			}
			else {
				cout << -1 << '\n';
			}
		}
	}
	return 0;
}