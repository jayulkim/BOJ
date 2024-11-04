#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0;
bool visited[5001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			v.push_back(n / 2 + 1);
			visited[n / 2 + 1] = true;
		}
		else {
			ll temp = v.back();
			for (int j = 1; j <= n; j++) {
				if (llabs(j - temp) >= n / 2 && !visited[j]) {
					visited[j] = true;
					v.push_back(j);
					break;
				}
			}
		}
	}
	for (auto& i : v) {
		cout << i << ' ';
	}
	return 0;
}