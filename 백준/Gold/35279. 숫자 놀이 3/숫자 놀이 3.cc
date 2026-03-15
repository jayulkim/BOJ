#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	map<ll, ll>Map;
	priority_queue<ll, vector<ll>, greater<ll>>pq;
	for (int i = 1; i < n; i++) {
		pq.push(i);
	}
	while (!pq.empty() && m) {
		ll temp = pq.top();
		pq.pop();
		m--;
		cout << temp << '\n';
		Map[temp]++;
		for (int i = 2; i <= 55; i++) {
			ll x = temp * i;
			ll count = 0;
			while (x) {
				count++;
				x /= n;
			}
			if (count == i && Map.find(temp * i) == Map.end()) {
				Map[temp * i]++;
				pq.push(temp * i);
			}
		}
	}
	return 0;
}