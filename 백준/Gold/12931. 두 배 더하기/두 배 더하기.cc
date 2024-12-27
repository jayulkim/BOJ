#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	ll result = 0;
	while (1) {
		bool find = false;
		bool a = false;
		for (auto& i : v) {
			if (i) {
				find = true;
			}
			if (i % 2) {
				result++;
				i--;
				a = true;
				break;
			}
		}
		if (!find) {
			break;
		}
		if (!a) {
			for (auto& i : v) {
				i /= 2;
			}
			result++;
		}
	}
	cout << result;
	return 0;
}