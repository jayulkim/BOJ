#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
vector<ll>v(10000001);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if (n == 1) {
		cout << 1;
	}
	else if (n == 2 || n == 5) {
		cout << -1;
	}
	else {
		vector<ll>v;
		vector<ll>result;
		ll a = n;
		while (n > 0) {
			ll temp = 1;
			while ((temp + 1) * (temp + 2) / 2 <= n) {
				temp++;
			}
			v.push_back(temp);
			n -= (temp * (temp + 1) / 2);
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i]; j++) {
				result.push_back(a);
			}
			if (i != v.size() - 1) {
				result.push_back(1);
			}
		}
		while (result.size() < a) {
			result.push_back(1);
		}
		for (auto& i : result) {
			cout << i << ' ';
		}
	}
	return 0;
}