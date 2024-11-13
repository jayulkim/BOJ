#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0;
ll a = 0, b = 0, c = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> a >> b >> c;
	priority_queue<pll>pq;
	for (int i = 1; i <= n; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		pq.push({ a + b + c, i });
	}
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		if (v.size() < m - 1) {
			if (a + b + c >= pq.top().first) {
				v.push_back(pq.top().second);
			}
			pq.pop();
		}
	}
	cout << 0 << ' ';
	for (auto& i : v) {
		cout << i << ' ';
	}
	return 0;
}