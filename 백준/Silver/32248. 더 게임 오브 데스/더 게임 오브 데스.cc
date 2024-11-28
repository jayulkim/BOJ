#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
bool visited[101];
ll parent[101];
ll v[101];
vector<ll>vv;
void game(ll x) {
	if (visited[x]) {
		vv.push_back(x);
		return;
	}
	vv.push_back(x);
	visited[x] = true;
	game(v[x]);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	game(1);
	ll target = vv.back();
	ll cyclelength = 0;
	vector<ll>cycle;
	for (int i = 0; i < vv.size(); i++) {
		if (!m) {
			cout << vv[i];
			return 0;
		}
		if (vv[i] == target) {
			for (int j = i; j < vv.size() - 1; j++) {
				cycle.push_back(vv[j]);
			}
			break;
		}
		m--;
	}
	cout << cycle[m % cycle.size()];
    return 0;
}