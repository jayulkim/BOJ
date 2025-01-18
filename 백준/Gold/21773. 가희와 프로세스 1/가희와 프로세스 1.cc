#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
struct info {
	ll id;
	ll time;
	ll num;
	bool operator()(const info& a, const info& b) {
		if (a.num == b.num) {
			return a.id > b.id;
		}
		return a.num < b.num;
	}
};
priority_queue<info, vector<info>, info>pq;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		pq.push({ a, b, c });
	}
	for (int i = 1; i <= n; i++) {
		info temp = pq.top();
		pq.pop();
		temp.num--;
		temp.time--;
		cout << temp.id << '\n';
		if (temp.time) {
			pq.push(temp);
		}
	}
	return 0;
}