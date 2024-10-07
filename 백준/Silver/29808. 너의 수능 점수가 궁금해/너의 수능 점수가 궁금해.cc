#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0;
vector<pair<ll, ll>>v;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if (n == 0) {
		cout << 1 << '\n';
		cout << 0 << ' ' << 0;
		return 0;
	}
	if (n % 4763) {
		cout << 0;
		return 0;
	}
	else {
		n /= 4763;
		bool a = false, b = false;
		if (n % 508 == 0 || n % 108 == 0) {
			a = true;
		}
		if (n % 212 == 0 || n % 305 == 0) {
			b = true;
		}
		for (ll i = 0; i <= 200; i++) {
			for (ll j = 0; j <= 200; j++) {
				if (i * 508 + j * 212 == n) {
					v.push_back({ i, j });
				}
				if (i * 508 + j * 305 == n) {
					v.push_back({ i, j });
				}
				if (i * 108 + j * 212 == n) {
					v.push_back({ i, j });
				}
				if (i * 108 + j * 305 == n) {
					v.push_back({ i, j });
				}
			}
		}
		if (!v.size()) {
			cout << 0;
			return 0;
		}
		sort(v.begin(), v.end());
		cout << v.size() << '\n';
		for (auto& i : v) {
			cout << i.first << ' ' << i.second << '\n';
		}
	}
	return 0;
}