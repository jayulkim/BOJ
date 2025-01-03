#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool visited[10001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i * i <= 10000; i++) {
		if (!visited[i]) {
			for (int j = i * i; j <= 10000; j += i) {
				visited[j] = true;
			}
		}
	}
	vector<ll>v;
	for (int i = 2; i <= 10000; i++) {
		if (!visited[i]) {
			v.push_back(i);
		}
	}
	vector<ll>vv;
	for (int i = 1; i < v.size(); i++) {
		vv.push_back(v[i] * v[i - 1]);
	}
	cin >> n;
	for (auto& i : vv) {
		if (i > n) {
			cout << i;
			return 0;
		}
	}
	return 0;
}