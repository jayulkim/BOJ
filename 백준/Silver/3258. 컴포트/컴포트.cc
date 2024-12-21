#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<bool>visited(1001, false);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		ll num = 0;
		cin >> num;
		visited[num - 1] = true;
	}
	for (int i = 1; i <= n; i++) {
		ll temp = 0;
		vector<bool>v = visited;
		while (1) {
			if (!v[(temp + i) % n]) {
				if ((temp + i) % n == m - 1) {
					cout << i;
					return 0;
				}
				v[(temp + i) % n] = true;
				temp += i;
			}
			else {
				break;
			}
		}
	}
	return 0;
}