#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<pll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back({ 0, num });
	}
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v[i].first = num;
	}
	sort(v.begin(), v.end());
	ll result = 0;
	result += v[0].second;
	priority_queue<ll>pq;
	for (int i = 1; i < n - 1; i += 2) {
		pq.push(v[i].second);
		pq.push(v[i + 1].second);
		result += pq.top();
		pq.pop();
	}
	cout << result;
	return 0;
}