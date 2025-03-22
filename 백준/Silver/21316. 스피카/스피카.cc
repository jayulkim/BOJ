#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[13];
ll degree[13];
vector<ll>v = { 1, 2, 3 };
bool check(ll start) {
	if (degree[start] == 3) {
		vector<ll>temp;
		for (auto& i : graph[start]) {
			temp.push_back(degree[i]);
		}
		sort(temp.begin(), temp.end());
		if (temp == v) {
			return true;
		}
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 12; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}
	for (int i = 1; i <= 12; i++) {
		if (check(i)) {
			cout << i;
			return 0;
		}
	}
	return 0;
}