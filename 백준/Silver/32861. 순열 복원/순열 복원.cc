#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Map[1001][1001];
bool visited[1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
		}
	}
	vector<ll>result;
	for (int i = 0; i < n; i++) {
		ll a = 0, b = 0;
		for (int j = 0; j < n; j++) {
			if (i == j && Map[i][j]) {
				cout << -1;
				return 0;
			}
			if (Map[i][j] == 1) {
				a++;
			}
			else if (Map[i][j] == -1) {
				b++;
			}
			else {
				if (i != j) {
					cout << -1;
					return 0;
				}
			}
		}
		result.push_back(b + 1);
	}
	for (auto& i : result) {
		if (visited[i]) {
			cout << -1;
			return 0;
		}
		visited[i] = true;
	}
	for (auto& i : result) {
		cout << i << ' ';
	}
	return 0;
}