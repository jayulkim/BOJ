#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	ll count = 1;
	while (num--) {
		ll n = 0, m = 0;
		priority_queue<pll, vector<pll>, greater<pll>>pq;
		priority_queue<ll, vector<ll>, greater<ll>>idxpq;
		cin >> n >> m;
		vector<pll>v;
		vector<bool>start(n + 1, false);
		for (int i = 1; i <= n; i++) {
			ll num = 0;
			cin >> num;
			v.push_back({ num, i });
		}
		sort(v.begin(), v.end());
		ll result = 0;
		for (int i = 0; i < n; i++) {
			while (!pq.empty() && pq.top().first < v[i].first - m) {
				start[pq.top().second] = false;
				pq.pop();
			}
			while (!idxpq.empty() && !start[idxpq.top()]) {
				idxpq.pop();
			}
			if (!idxpq.empty() && v[i].second > idxpq.top()) {
				result += (v[i].second - idxpq.top());
			}
			pq.push({ v[i].first, v[i].second });
			idxpq.push(v[i].second);
			start[v[i].second] = true;
		}
		cout << "Case #" << count << '\n';
		cout << result << '\n';
		count++;
	}
	return 0; 
}