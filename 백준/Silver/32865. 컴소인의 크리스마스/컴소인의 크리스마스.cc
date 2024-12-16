#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v;
	priority_queue<pll>pq;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		if (!num) {
			v.push_back(i + 1);
		}
		else {
			pq.push({ num, i + 1 });
		}
	}
	vector<ll>result;
	for (int i = 0; i < 2 * n - 2; i++) {
		if (i % 2) {
			if (!pq.empty()) {
				pll temp = pq.top();
				result.push_back(temp.second);
				pq.pop();
				if (temp.first - 1 != 0) {
					pq.push({ temp.first - 1, temp.second });
				}
				else {
					v.push_back(temp.second);
				}
			}
			else {
				cout << -1;
				return 0;
			}
		}
		else {
			if (!v.size()) {
				cout << -1;
				return 0;
			}
			else {
				result.push_back(v.back());
				v.pop_back();
			}
		}
	}
	if (pq.empty() && v.size() == 1) {
		for (auto& i : result) {
			cout << i << '\n';
		}
		cout << v.back();
		return 0;
	}
	cout << -1;
	return 0;
}