#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	string str = "";
	cin >> str;
	string a = "", b = "";
	string temp = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '*') {
			a = temp;
			temp = "";
			for (int j = i + 1; j < str.length(); j++) {
				temp += str[j];
			}
			b = temp;
			break;
		}
		else {
			temp += str[i];
		}
	}
	for (int i = 0; i < n; i++) {
		string temp = "";
		cin >> temp;
		bool find = false;
		vector<bool>visited(101, false);
		for (int j = 0; j < a.length(); j++) {
			if (temp[j] != a[j]) {
				find = true;
				break;
			}
			visited[j] = true;
		}
		if (!find) {
			ll idx = temp.length() - 1;
			for (int j = 0; j < b.length(); j++) {
				if (temp[idx - j] != b[b.length() - 1 - j]) {
					find = true;
					break;
				}
				else if (visited[idx - j]) {
					find = true;
					break;
				}
			}
			if (!find) {
				cout << "DA" << '\n';
			}
			else {
				cout << "NE" << '\n';
			}
		}
		else {
			cout << "NE" << '\n';
		}
	}
	return 0;
}