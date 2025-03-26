#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	priority_queue<ll>pq;
	ll result = k;
	ll count = 0;
	for (int i = 0; i < n && count < m; i++) {
		if (v[i] < k) {
			pq.push(v[i]);
		}
		else {
			if (pq.empty()) {
				break;
			}
			result += pq.top();
			k += pq.top();
			pq.pop();
			count++;
			i--;
		}
	}
	while (!pq.empty() && count < m) {
		result += pq.top();
		pq.pop();
		count++;
	}
	cout << result;
	return 0;
}