#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	vector<string>name;
	priority_queue<ll, vector<ll>, greater<ll>>pq[36];
	for (int i = 0; i < n; i++) {
		string str = "";
		cin >> str;
		name.push_back(str);
		for (int j = 0; j < m; j++) {
			ll num = 0;
			cin >> num;
			pq[i].push(num);
		}
	}
	vector<string>result;
	while (result.size() < n) {
		bool find = false;
		ll idx = -1;
		ll Min = LLONG_MAX;
		for (int i = 0; i < n; i++) {
			if (!pq[i].empty() && Min > pq[i].top()) {
				Min = pq[i].top();
				idx = i;
			}
			else if (!pq[i].empty() && Min == pq[i].top()) {
				if (name[idx] > name[i]) {
					idx = i;
				}
			}
		}
		pq[idx].pop();
		if (pq[idx].empty()) {
			result.push_back(name[idx]);
		}
		for (int i = 0; i < n; i++) {
			if (i != idx && !pq[i].empty()) {
				ll temp = pq[i].top();
				pq[i].pop();
				pq[i].push(temp + k);
			}
		}
	}
	for (auto& i : result) {
		cout << i << ' ';
	}
	return 0;
}