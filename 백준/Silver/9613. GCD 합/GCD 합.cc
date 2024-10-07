#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	ll temp = a % b;
	while (temp > 0) {
		a = b;
		b = temp;
		temp = a % b;
	}
	return b;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		string str = "";
		ll n = 0;
		cin >> n;
		vector<ll>v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		ll sum = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			for (int j = i + 1; j < v.size(); j++) {
				sum += gcd(v[i], v[j]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}