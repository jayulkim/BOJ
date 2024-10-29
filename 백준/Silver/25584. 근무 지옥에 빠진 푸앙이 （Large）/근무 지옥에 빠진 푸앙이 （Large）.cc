#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, ll>Map;
vector<ll>ary = { 4, 6, 4, 10 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string str = "";
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 7; k++) {
				string temp = "";
				cin >> temp;
				if (temp != "-") {
					Map[temp] += ary[j];
				}
			}
		}
	}
	vector<ll>v;
	for (auto& i : Map) {
		v.push_back(i.second);
	}
	if (v.empty()) {
		cout << "Yes";
		return 0;
	}
	sort(v.begin(), v.end());
	if (v.back() - v[0] <= 12) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}