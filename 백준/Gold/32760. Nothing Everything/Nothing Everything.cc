#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		if (start < end) {
			swap(start, end);
		}
		graph[start].push_back(end);
	}
	string result = "";
	for (int i = 2; i <= n; i++) {
		if (graph[i].size() == i - 1) {
			result += 'E';
		}
		else if (!graph[i].size()) {
			result += 'N';
		}
		else {
			cout << -1;
			return 0;
		}
	}
	cout << result;
	return 0;
}