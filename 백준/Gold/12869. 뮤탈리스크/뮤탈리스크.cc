#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
vector<ll>v;
map<vector<ll>, ll>Map;
vector<ll>vvv = { 9, 3, 1 };
void bfs() {
	queue<pair<vector<ll>, ll>>q;
	q.push({ v, 0 });
	while (!q.empty()) {
		pair<vector<ll>, ll>temp = q.front();
		q.pop();
		bool find = false;
		for (auto& i : temp.first) {
			if (i > 0) {
				find = true;
				break;
			}
		}
		if (!find) {
			cout << temp.second;
			return;
		}
		Map[temp.first]++;
		sort(temp.first.begin(), temp.first.end());
		do {
			vector<ll>vv;
			for (int i = 0; i < temp.first.size(); i++) {
				if (temp.first[i] - vvv[i] > 0) {
					vv.push_back(temp.first[i] - vvv[i]);
				}
			}
			if (!Map[vv]) {
				q.push({ vv, temp.second + 1 });
				Map[vv]++;
			}
		} while (next_permutation(temp.first.begin(), temp.first.end()));
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	bfs();
	return 0;
}