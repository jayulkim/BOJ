#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Gcd(ll x, ll y) {
	ll temp = x % y;
	while (temp > 0) {
		x = y;
		y = temp;
		temp = x % y;
	}
	return y;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> n;
		if (!n) {
			break;
		}
		vector<ll>v;
		vector<bool>visited(101, false);
		for (int i = 0; i < n; i++) {
			ll num = 0;
			cin >> num;
			v.push_back(num);
		}
		ll count = 0;
		for (int i = 1; i <= 100; i++) {
			if (!visited[i]) {
				ll temp = v[0];
				bool find = false;
				for (int j = 1; j < n; j++) {
					if (temp == i) {
						find = true;
						count++;
						visited[i] = true;
						break;
					}
					if (temp % i) {
						temp = v[j];
					}
					temp = Gcd(temp, v[j]);
				}
				if (!find && temp == i) {
					count++;
				}
			}
			else {
				count++;
			}
		}
		cout << count << '\n';
	}
	return 0;
}