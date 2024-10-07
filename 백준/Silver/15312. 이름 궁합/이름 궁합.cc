#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ary[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a = "", b = "";
	cin >> a >> b;
	int result = 0;
	vector<int>v;
	vector<int>vv;
	for (int i = 0; i < a.length(); i++) {
		v.push_back(ary[a[i] - 65]);
		v.push_back(ary[b[i] - 65]);
	}
	while (1) {
		for (int i = 0; i < v.size() - 1; i++) {
			vv.push_back((v[i] + v[i + 1]) % 10);
		}
		vector<int>().swap(v);
		if (vv.size() == 2) {
			for (auto& i : vv) {
				cout << i;
			}
			return 0;
		}
		for (int i = 0; i < vv.size() - 1; i++) {
			v.push_back((vv[i] + vv[i + 1]) % 10);
		}
		vector<int>().swap(vv);
		if (v.size() == 2) {
			for (auto& i : v) {
				cout << i;
			}
			return 0;
		}
	}
	return 0;
}