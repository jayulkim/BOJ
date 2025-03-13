#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;
map<pll, ll>visited;
void bfs(ll a, ll b, ll n, ll m, ll enda, ll endb) {
	visited[{a, b}]++;
	queue<lll>q;
	q.push({ a, b, 0 });
	while (!q.empty()) {
		auto [a, b, c] = q.front();
		q.pop();
		if (a == enda && b == endb) {
			cout << c;
			exit(0);
		}
		visited[{a, b}]++;
		if (!visited[{n, b}]) {
			visited[{n, b}]++;
			q.push({ n, b, c + 1 });
		}
		if (!visited[{a, m}]) {
			visited[{a, m}]++;
			q.push({ a, m, c + 1 });
		}
		if (!visited[{a, 0}]) {
			visited[{a, 0}]++;
			q.push({ a, 0, c + 1 });
		}
		if (!visited[{0, b}]) {
			visited[{0, b}]++;
			q.push({ 0, b, c + 1 });
		}
		if (a + b <= n) {
			if (!visited[{a + b, 0}]) {
				visited[{a + b, 0}]++;
				q.push({ a + b, 0, c + 1 });
			}
		}
		else {
			if (!visited[{n, a + b - n}]) {
				visited[{n, a + b - n}]++;
				q.push({ n, a + b - n, c + 1 });
			}
		}
		if (a + b <= m) {
			if (!visited[{0, a + b}]) {
				visited[{0, a + b}]++;
				q.push({ 0, a + b, c + 1 });
			}
		}
		else {
			if (!visited[{a + b - m, m}]) {
				visited[{a + b - m, m}]++;
				q.push({ a + b - m, m, c + 1 });
			}
		}
	}
}
int main(void) { 
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	bfs(0, 0, a, b, c, d);
	cout << -1;
	return 0;
}