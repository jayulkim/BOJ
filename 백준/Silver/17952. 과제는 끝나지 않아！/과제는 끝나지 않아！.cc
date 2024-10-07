#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, result = 0;
	cin >> n;
	stack<pair<ll, ll>>s;
	for (int i = 0; i < n; i++) {
		int command = 0, score = 0, min = 0;
		cin >> command;
		if (command == 1) {
			cin >> score >> min;
			min--;
			if (!min) {
				result += score;
			}
			else {
				s.push({ score, min });
			}
		}
		else {
			if (!s.empty()) {
				pair<ll, ll>temp = s.top();
				s.pop();
				temp.second--;
				if (!temp.second) {
					result += temp.first;
				}
				else {
					s.push({ temp.first, temp.second });
				}
			}
		}
	}
	cout << result;
	return 0;
}