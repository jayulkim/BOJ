#include <bits/stdc++.h>
using namespace std;
bool visited[97];
vector<string>v;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string str = "";
		getline(cin, str);
		str += ' ';
		string temp = "";
		for (auto& i : str) {
			if (i == ' ') {
				v.push_back(temp);
				temp = "";
			}
			else {
				temp += i;
			}
		}
		int idx1 = -1;
		int idx2 = -1;
		for (int j = 0; j < v.size(); j++) {
			bool find = false;
			if (!visited[(int)toupper(v[j][0])]) {
				idx1 = j;
				idx2 = 0;
				find = true;
				visited[(int)toupper(v[j][0])] = true;
				break;
			}
			if (find) {
				break;
			}
		}
		if (idx1 != -1 && idx2 == 0) {
			for (int j = 0; j < v.size(); j++) {
				if (j == idx1) {
					cout << '[' << v[j][idx2] << ']';
					for (int k = 1; k < v[j].length(); k++) {
						cout << v[j][k];
					}
				}
				else {
					cout << v[j];
				}
				cout << ' ';
			}
		}
		else {
			for (int j = 0; j < v.size(); j++) {
				bool find = false;
				for (int k = 0; k < v[j].length(); k++) {
					if (!visited[(int)toupper(v[j][k])]) {
						idx1 = j;
						idx2 = k;
						find = true;
						visited[(int)toupper(v[j][k])] = true;
						break;
					}
				}
				if (find) {
					break;
				}
			}
			if (idx1 != -1 && idx2 != -1) {
				for (int j = 0; j < v.size(); j++) {
					for (int k = 0; k < v[j].length(); k++) {
						if (j == idx1 && k == idx2) {
							cout << '[';
						}
						cout << v[j][k];
						if (j == idx1 && k == idx2) {
							cout << ']';
						}
					}
					cout << ' ';
				}
			}
			else {
				for (int j = 0; j < v.size(); j++) {
					cout << v[j] << ' ';
				}
			}
		}
		cout << '\n';
		vector<string>().swap(v);
	}

	return 0;
}