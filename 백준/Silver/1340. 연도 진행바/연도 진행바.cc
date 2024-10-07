#include <bits/stdc++.h>
using namespace std;
int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pair<string, int>>m;
	m.push_back({ "January", 1 });
	m.push_back({ "February", 2 });
	m.push_back({ "March", 3 });
	m.push_back({ "April", 4 });
	m.push_back({ "May", 5 });
	m.push_back({ "June", 6 });
	m.push_back({ "July", 7 });
	m.push_back({ "August", 8 });
	m.push_back({ "September", 9 });
	m.push_back({ "October", 10 });
	m.push_back({ "November", 11 });
	m.push_back({ "December", 12 });
	string str = "";
	getline(cin, str);
	str += ' ';
	vector<string>v;
	string temp = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			v.push_back(temp);
			temp = "";
		}
		else {
			temp += str[i];
		}
	}
	int sum = 0;
	for (int i = 0; i < 12; i++) {
		if (m[i].first == v[0]) {
			break;
		}
		if (m[i].first == "February" && ((stoi(v[2]) % 4 == 0 && stoi(v[2]) % 100 != 0) || stoi(v[2]) % 400 == 0)) {
			sum++;
		}
		sum += month[m[i].second];
	}
	v[1].pop_back();
	sum--;
	sum += stoi(v[1]);
	sum *= 24;
	sum *= 60;
	string hour = "";
	string min = "";
	hour += v[3][0];
	hour += v[3][1];
	min += v[3][3];
	min += v[3][4];
	sum += stoi(min);
	sum += (stoi(hour) * 60);
	cout << fixed;
	cout.precision(50);
	if ((stoi(v[2]) % 4 == 0 && stoi(v[2]) % 100 != 0) || stoi(v[2]) % 400 == 0) {
		cout << ((double)sum / (double)527040) * 100.0;
	}
	else {
		cout << ((double)sum / (double)525600) * 100.0;
	}
	return 0;
}