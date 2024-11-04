#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>v;
vector<ll>result;
bool visited[21];
ll temp = -1;
ll Min = LLONG_MAX;
vector<ll>ary;
void dfs() {
	if (result.size() == m) {
		ll sum = 0;
		for (auto& i : v) {
			ll temp = LLONG_MAX;
			for (auto& j : result) {
				temp = min(temp, min(llabs(i - j), k - llabs(i - j)));
			}
			sum += temp;
		}
		if (Min > sum) {
			Min = sum;
			ary = result;
		}
		return;
	}
	for (int i = temp + 1; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			result.push_back(v[i]);
			temp = i;
			dfs();
			result.pop_back();
			visited[i] = false;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	dfs();
	cout << Min << '\n';
	for (auto& i : ary) {
		cout << i << ' ';
	}
	return 0;
}