#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll degree[100001];
vector<ll>graph[100001];
bool visited[100001];
void toposort() {
	queue<ll>q;
	ll count = 0;
	for (int i = 0; i < n; i++) {
		if (degree[i] == 1) {
			q.push(i);
			count++;
		}
	}
	if (count > 2) {
		while (1) {
			count = 0;
			vector<ll>v;
			while (!q.empty()) {
				ll temp = q.front();
				q.pop();
				degree[temp] = -1;
				for (auto& i : graph[temp]) {
					if (--degree[i] == 1) {
						v.push_back(i);
						count++;
					}
				}
			}
			if (count > 2) {
				for (auto& i : v) {
					q.push(i);
				}
			}
			else {
				break;
			}
		}
	}
	bool find = false;
	vector<ll>result;
	for (int i = 0; i < n; i++) {
		if (degree[i] == 1 || degree[i] == 2) {
			result.push_back(i);
			find = true;
		}
	}
	if (!find) {
		for (int i = 0; i < n; i++) {
			if (!degree[i]) {
				cout << i;
				break;
			}
		}
	}
	else {
		sort(result.begin(), result.end());
		for (auto& i : result) {
			cout << i << ' ';
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		degree[a]++;
		degree[b]++;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	toposort();
	return 0;
}