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
	string str = "";
	cin >> str;
	if (str == "0.0") {
		cout << -1;
		return 0;
	}
	string temp = str;
	temp.pop_back();
	temp.pop_back();
	n = stoll(temp);
	n *= 10;
	n += (str.back() - '0');
	vector<ll>v = { 90, 70, 45, -20 };
	ll count = 0;
	if (n > lcm(90, 70)) {
		count = 7 * (n / lcm(90, 70) - 1);
		n %= lcm(90, 70);
		n += lcm(90, 70);
	}
	else {
		n %= lcm(90, 70);
	}
	vector<ll>dist(n * 10 + 1, LLONG_MAX);
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	pq.push({ 0, 0 });
	dist[0] = 0;
	while (!pq.empty()) {
		auto [a, b] = pq.top();
		pq.pop();
		if (dist[b] >= a) {
			for (auto& i : v) {
				if (b + i >= 0 && b + i <= n * 10 && dist[b + i] > dist[b] + 1) {
					dist[b + i] = dist[b] + 1;
					pq.push({ dist[b + i], b + i });
				}
			}
		}
	}
	if (dist[n] == LLONG_MAX) {
		cout << -1;
		return 0;
	}
	cout << dist[n] + count;
	return 0;
}