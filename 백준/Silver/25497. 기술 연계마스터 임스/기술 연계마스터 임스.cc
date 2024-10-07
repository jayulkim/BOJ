#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	stack<char>s1;
	stack<char>s2;
	int count = 0;
	string skill = "";
	cin >> skill;
	for (int i = 0; i < n; i++) {
		if (skill[i] <= '9' && skill[i] >= '1') {
			count++;
		}
		else if (skill[i] == 'S') {
			s1.push(skill[i]);
		}
		else if (skill[i] == 'L') {
			s2.push(skill[i]);
		}
		else if (skill[i] == 'R') {
			if (!s2.empty() && s2.top() == 'L') {
				s2.pop();
				count++;
			}
			else {
				cout << count;
				return 0;
			}
		}
		else if (skill[i] == 'K') {
			if (!s1.empty() && s1.top() == 'S') {
				s1.pop();
				count++;
			}
			else {
				cout << count;
				return 0;
			}
		}
	}
	cout << count;
	return 0;
}