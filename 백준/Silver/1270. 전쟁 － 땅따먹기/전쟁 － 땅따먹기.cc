#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	map<ll, int>Map;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m = 0;
		cin >> m;
		vector<ll>v;
		for (int j = 0; j < m; j++) {
			ll num = 0;
			cin >> num;
			v.push_back(num);
			if (Map.find(num) == Map.end()) {
				Map.insert({ num, 1 });
			}
			else {
				Map.find(num)->second++;
			}
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		int Max = 0;
		ll number = 0;
		for (auto& i : v) {
			if (Max < Map.find(i)->second) {
				Max = Map.find(i)->second;
				number = i;
			}
		}
		if (Max > m / 2) {
			cout << number << '\n';
		}
		else {
			cout << "SYJKGW" << '\n';
		}
		map<ll, int>().swap(Map);
		vector<ll>().swap(v);
	} 
	return 0;
}