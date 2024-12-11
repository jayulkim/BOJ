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
	getline(cin, str);
	str += ' ';
	string temp = "";
	ll a = 0, b = 0;
	vector<string>v;
	for (auto& i : str) {
		if (i == ' ') {
			if (temp == "se" || temp == "no" || temp == "hai" || temp == "u-" || temp == "hai-" || temp == "mik-jjang" || temp == "kawaii!" || temp == "Are" || temp == "you" || temp == "ready" || temp == "antena" || temp == "senku" || temp == "high!") {
				v.push_back(temp);
			}
			temp = "";
		}
		else {
			temp += i;
		}
	}
	ll idx = 0;
	bool aa = false;
	while (idx < v.size()) {
		if (v[idx] == "se") {
			ll count = 0;
			bool find = false;
			ll temp = 0;
			for (int i = idx + 1; i < v.size(); i++) {
				if (!count && v[i] == "no") {
					count++;
				}
				else if (count == 1 && v[i] == "hai-") {
					count++;
				}
				else if (count == 2 && v[i] == "hai-") {
					count++;
				}
				else if (count == 3 && v[i] == "hai") {
					count++;
				}
				else if (count == 4 && v[i] == "hai") {
					count++;
				}
				else if (count == 5 && v[i] == "hai") {
					count++;
				}
				else if (count == 6 && v[i] == "hai") {
					count++;
				}
				else if (count == 7 && v[i] == "u-") {
					count++;
				}
				else if (count == 8 && v[i] == "hai") {
					count++;
					temp = i;
					break;
				}
			}
			if (count == 9) {
				idx = temp;
				a++;
				b++;
			}
			aa = true;
		}
		else if (v[idx] == "mik-jjang") {
			ll temp = 0;
			for (int i = idx + 1; i < v.size(); i++) {
				if (v[i] == "kawaii!") {
					idx = i;
					a++;
					b++;
					break;
				}
			}
			aa = false;
		}
		else if (v[idx] == "Are") {
			ll count = 0;
			ll temp = 0;
			for (int i = idx + 1; i < v.size(); i++) {
				if (!count && v[i] == "you") {
					count++;
				}
				else if (count == 1 && v[i] == "ready") {
					count++;
				}
				else if (count == 2 && v[i] == "antena") {
					count++;
				}
				else if (count == 3 && v[i] == "senku") {
					count++;
				}
				else if (count == 4 && v[i] == "high!") {
					count++;
					temp = i;
				}
			}
			if (count == 5) {
				idx = temp;
				a++;
				b++;
			}
			aa = false;
		}
		else if (v[idx] == "u-") {
			for (int i = idx + 1; i < v.size(); i++) {
				if (v[i] == "hai") {
					idx = i;
					if (!aa) {
						b++;
					}
					break;
				}
			}
		}
		else if (v[idx] == "hai") {
			b++;
			aa = false;
		}
		idx++;
	}
	cout << a << ' ' << b;
	return 0;
}