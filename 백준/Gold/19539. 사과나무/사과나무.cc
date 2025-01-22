#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	priority_queue<ll>pq;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		if (num) {
			sum += num;
			pq.push(num);
		}
	}
	if (sum % 3) {
		cout << "NO";
		return 0;
	}
	ll a = (sum / 3);
	if (!a) {
		cout << "YES";
		return 0;
	}
	while (!pq.empty()) {
		ll temp = pq.top();
		pq.pop();
		a -= (temp / 2);
		if (a <= 0) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}