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
	priority_queue<pll>pq;
	vector<pll>v;
	for (int i = 0; i < n; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		v.push_back({ b, a });
	}
	ll sum = 0;
	bool find = false;
	for (int i = 0; i < n; i++) {
		if (sum > v[i].second) {
			if (find) {
				cout << "Zzz";
				return 0;
			}
			if (pq.top().first < v[i].first || sum - pq.top().first > v[i].second) {
				find = true;
				continue;
			}
			else {
				sum -= pq.top().first;
				pq.pop();
				if (sum > v[i].second) {
					cout << "Zzz";
					return 0;
				}
				sum += v[i].first;
				pq.push(v[i]);
				find = true;
			}
		}
		else {
			sum += v[i].first;
			pq.push(v[i]);
		}
	}
	cout << "Kkeo-eok";
	return 0;
}