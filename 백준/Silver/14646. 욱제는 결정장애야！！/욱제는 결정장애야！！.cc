#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll num = 0;
bool visited[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		cin >> v[i];
	}
	ll count = 0, Max = 0;
	for (auto& i : v) {
		if (!visited[i]) {
			count++;
			visited[i] = true;
		}
		else {
			count--;
		}
		Max = max(Max, count);
	}
	cout << Max;
	return 0;
}