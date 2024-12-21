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
	ll count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str = "";
		cin >> str;
		string temp = "";
		for (auto& j : str) {
			if (temp == "") {
				temp += j;
			}
			else {
				if (temp.back() == j) {
					temp.pop_back();
				}
				else {
					temp.push_back(j);
				}
			}
		}
		if (temp == "") {
			count++;
		}
	}
	cout << count;
	return 0;
}