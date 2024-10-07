#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n = 0;
map<string, int>Map;
priority_queue<ll>pq[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ll result = 0;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		int command = 0;
		string str = "";
		int k = 0;
		cin >> command >> str;
		if (command == 1) {
			cin >> k;
			if (Map.find(str) == Map.end()) {
				Map.insert({ str, idx });
				for (int i = 0; i < k; i++) {
					ll num = 0;
					cin >> num;
					pq[idx].push(num);
				}
				idx++;
			}
			else {
				int temp = Map[str];
				for (int i = 0; i < k; i++) {
					ll num = 0;
					cin >> num;
					pq[temp].push(num);
				}
			}
		}
		else {
			cin >> k;
			if (Map.find(str) != Map.end()) {
				int temp = Map[str];
				for (int i = 0; i < k; i++) {
					if (!pq[temp].empty()) {
						result += pq[temp].top();
						pq[temp].pop();
					}
				}
			}
		}
	}
	cout << result;
	return 0;
}