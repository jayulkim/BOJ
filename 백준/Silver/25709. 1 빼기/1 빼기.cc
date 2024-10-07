#include <bits/stdc++.h>
using namespace std;
set<string>s;
void bfs(string start) {
	s.insert(start);
	queue<pair<string, int>>q;
	q.push({start, 0});
	while (!q.empty()) {
		pair<string, int>temp = q.front();
		q.pop();
		if (temp.first == "0" || temp.first == "00" || temp.first == "000" || temp.first == "0000" || temp.first == "00000" || temp.first == "000000" || temp.first == "0000000" || temp.first == "00000000" || temp.first == "000000000" || temp.first == "0000000000") {
			cout << temp.second;
			return;
		}
		if (stoi(temp.first) - 1 >= 0 && s.find(to_string(stoi(temp.first) - 1)) == s.end()) {
			string str = to_string(stoi(temp.first) - 1);
			q.push({ str, temp.second + 1 });
			s.insert(str);
		}
		for (int i = 0; i < temp.first.length(); i++) {
			if (temp.first[i] == '1') {
				string left = "";
				string right = "";
				for (int j = 0; j < i; j++) {
					left += temp.first[j];
				}
				for (int j = i + 1; j < temp.first.length(); j++) {
					right += temp.first[j];
				}
				string result = left + right;
				if (result != "" && stoi(result) <= 1000000000 && stoi(result) >= 0 && s.find(result) == s.end()) {
					q.push({ result, temp.second + 1 });
					s.insert(result);
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string n = "";
	cin >> n;
	bfs(n);
	return 0;
}