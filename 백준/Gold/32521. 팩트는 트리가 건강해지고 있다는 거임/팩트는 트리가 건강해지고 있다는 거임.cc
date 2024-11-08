#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0;
vector<ll>v;
vector<ll>graph[100001];
ll result = 0;
ll dfs(ll parent, ll node) {
	vector<ll>temp;
	ll count = v[node - 1];
	for (auto& i : graph[node]) {
		if (parent != i) {
			temp.push_back(dfs(node, i));
		}
	}
	sort(temp.begin(), temp.end());
	for (int i = 0; i < temp.size(); i++) {
		ll a = count + temp[i];
		if (a > m) {
			result += temp.size() - i;
			break;
		}
		count = a;
	}
	return count;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n - 1; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	dfs(-1, 1);
	cout << result;
	return 0;
}