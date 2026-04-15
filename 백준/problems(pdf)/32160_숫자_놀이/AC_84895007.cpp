#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	queue<ll>q;
	for (int i = n - 1; i >= 1; i--) {
		q.push(i);
	}
	vector<pair<ll, ll>>v;
	while (q.size() > 1) {
		ll a = q.front();
		q.pop();
		ll b = q.front();
		q.pop();
		v.push_back({ a, b });
		q.push(llabs(a - b));
	}
	cout << n - q.front() << '\n';
	for (auto& i : v) {
		cout << i.first << ' ' << i.second << '\n';
	}
	cout << q.front() << ' ' << n << '\n';
 	return 0;
}