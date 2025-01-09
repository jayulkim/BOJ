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
	cin >> n;
	vector<ll>v;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		ll num = 0;
		cin >> num;
		if (num) {
			sum += num;
			v.push_back(i);
		}
	}
	if (sum) {
		for (int i = 0; i < v.size() - 1; i++) {
			sum += (llabs((v[i + 1] - v[i])) / 2);
		}
		sum += ((v[0] + n - v.back()) / 2);
		cout << sum;
	}
	else {
		cout << sum + n / 2;
	}
	return 0;
}