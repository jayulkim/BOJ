#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[20001];
vector<ll>v;
bool visited[20001];
ll gcd(ll a, ll b) {
	ll temp = a % b;
	while (temp > 0) {
		a = b;
		b = temp;
		temp = a % b;
	}
	return b;
}
ll bfs(ll start) {
	ll result = 0;
	visited[start] = true;
	queue<ll>q;
	q.push(start);
	while (!q.empty()) {
		ll temp = q.front();
		q.pop();
		result++;
		visited[temp] = true;
		for (auto& i : graph[temp]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		graph[i].push_back(m);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			v.push_back(bfs(i));
		}
	}
	ll result = 1;
	for (auto& i : v) {
		result = result * i / gcd(result, i);
	}
	cout << result; 
	return 0;
}