#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	getline(cin, str);
	vector<string>v;
	string token = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			v.push_back(token);
			token = "";
		}
		else if (str[i] == '<' || str[i] == '>' || str[i] == '(' || str[i] == ')') {
			v.push_back(token);
			string temp = "";
			temp += str[i];
			v.push_back(temp);
			token = "";
		}
		else if (i < str.length() - 1 && ((str[i] == '&' && str[i + 1] == '&') || (str[i] == '|' && str[i + 1] == '|'))) {
			v.push_back(token);
			string temp = "";
			temp += str[i];
			temp += str[i + 1];
			v.push_back(temp);
			token = "";
			i++;
		}
		else {
			token += str[i];
		}
	}
	if (token != "") {
		v.push_back(token);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != "") {
			cout << v[i] << ' ';
		}
	}
	return 0;
}