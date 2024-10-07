#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
map<vector<ll>, ll>Map;
vector<ll>v[101];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ll Max = 0;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		while (1) {
			cin >> num;
			if (num == -1) {
				break;
			}
			v[i].push_back(num);
		}
		Max = max(Max, (ll)v[i].size());
	}
	for (int i = 0; i < n; i++) {
		while (v[i].size() < Max) {
			v[i].push_back(0);
		}
	}
	for (int i = 1; i <= Max; i++) {
		bool find = false;
		for (int j = 0; j < n; j++) {
			vector<ll>temp;
			for (int k = 0; k < i; k++) {
				temp.push_back(v[j][k]);
			}
			if (!Map[temp]) {
				Map[temp]++;
			}
			else {
				find = true;
				map<vector<ll>, ll>().swap(Map);
				break;
			}
		}
		if (!find) {
			cout << i;
			return 0;
		}
	}
	return 0; 
}