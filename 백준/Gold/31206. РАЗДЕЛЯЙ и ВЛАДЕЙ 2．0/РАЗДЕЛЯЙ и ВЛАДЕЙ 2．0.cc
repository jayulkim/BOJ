#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[200001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ll num = 0;
		cin >> num;
		for (int j = 1; j * j <= num; j++) {
			if (j * j == num) {
				graph[j].push_back(i);
			}
			else if (num % j == 0) {
				graph[j].push_back(i);
				graph[num / j].push_back(i);
			}
		}
		for (int j = num * 2; j <= 200000; j += num) {
			graph[j].push_back(i);
		}
	}
	vector<ll>result;
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0, temp = 0;
		cin >> start >> end >> temp;
		auto it = upper_bound(graph[temp].begin(), graph[temp].end(), end);
		it--;
		result.push_back((it - graph[temp].begin()) - (lower_bound(graph[temp].begin(), graph[temp].end(), start) - graph[temp].begin()) + 1);
	}
	for (auto& i : result) {
		cout << i << ' ';
	}
	return 0;
}