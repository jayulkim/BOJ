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
	string str = "";
	while (1) {
		cin >> str;
		if (str == "*") {
			break;
		}
		bool find = false;
		for (int i = 1; i <= str.length() - 1; i++) {
			map<string, ll>Map;	
			for (int j = 0; j < str.length() - i; j++) {
				string temp = "";
				for (int k = j; k <= j + i; k += i) {
					temp += str[k];
				}
				if (!Map[temp]) {
					Map[temp]++;
				}
				else {
					find = true;
					cout << str << ' ' << "is NOT surprising." << '\n';
					break;
				}
			}
			if (find) {
				break;
			}
		}
		if (!find) {
			cout << str << ' ' << "is surprising." << '\n';
		}
	}
	return 0;
}