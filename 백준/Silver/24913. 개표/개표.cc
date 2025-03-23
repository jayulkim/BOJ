#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, char> llc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll dp[100001];
ll visited[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<lll, vector<lll>, greater<lll>>pq;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 1) {
			dp[c] += b;
			visited[c] = i;
			if (c != n + 1) {
				pq.push({ dp[c], i, c });
			}
		}
		else {
			while (!pq.empty() && visited[get<2>(pq.top())] != get<1>(pq.top())) {
				pq.pop();
			}
			if (!pq.empty()) {
				if (dp[n + 1] + b > get<0>(pq.top()) + c) {
					cout << "YES" << '\n';
				}
				else {
					cout << "NO" << '\n';
				}
			}
			else {
				if (dp[n + 1] + b > c) {
					cout << "YES" << '\n';
				}
				else {
					cout << "NO" << '\n';
				}
			}
		}
	}
	return 0;
}