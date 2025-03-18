#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>v;
bool visited[100001];
void bfs(ll start) {
	visited[start] = true;
	queue<ll>q;
	q.push(start);
	while (!q.empty()) {
		ll temp = q.front();
		q.pop();
		visited[temp] = true;
		if (temp - v[temp] >= 0) {
			visited[temp - v[temp]] = true;
			q.push(temp - v[temp]);
		}
		if (temp + v[temp] < n) {
			visited[temp + v[temp]] = true;
			q.push(temp + v[temp]);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	cin >> m;
	bfs(m - 1);
	ll count = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			count++;
		}
	}
	cout << count;
	return 0;
}