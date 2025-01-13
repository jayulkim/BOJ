#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
ll a = 0, b = 0, c = 0, d = 0;
vector<ll>v;
bool visited[16];
vector<ll>result;
ll num = 0;
ll temp = -1;
void dfs(ll n) {
	if (result.size() == n) {
		if (result.back() - result.front() >= d) {
			ll sum = 0;
			for (auto& i : result) {
				sum += i;
			}
			if (sum >= b && sum <= c) {
				num++;
			}
		}
		return;
	}
	for (int i = temp + 1; i < v.size(); i++) {
		if (!visited[i]) {
			result.push_back(v[i]);
			visited[i] = true;
			temp = i;
			dfs(n);
			visited[i] = false;
			result.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> c >> d;
	for (int i = 0; i < a; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 2; i <= a; i++) {
		dfs(i);
		temp = -1;
	}
	cout << num;
	return 0;
}