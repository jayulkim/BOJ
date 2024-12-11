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
	ll num = 0;
	ll count = 1;
	cin >> num;
	cin.ignore();
	while (num--) {
		string size = "";
		string str = "";
		getline(cin, size);
		vector<string>v;
		for (auto& i : size) {
			if (i == ' ') {
				v.push_back(str);
				str = "";
			}
			else {
				str += i;
			}
		}
		if (str != "") {
			v.push_back(str);
		}
		n = stoll(v[2]);
		m = stoll(v[4]);
		string stal = "";
		str = "";
		getline(cin, stal);
		ll temp = 0;
		vector<string>vv;
		for (auto& i : stal) {
			if (i == ' ') {
				vv.push_back(str);
				str = "";
			}
			else {
				str += i;
			}
		}
		temp = stoll(vv.back());
		vector<ll>vvv(m + 1, 0);
		for (int i = 0; i < temp; i++) {
			string str = "";
			string s = "";
			getline(cin, str);
			ll a = 0, b = 0;
			vector<string>vvvv;
			bool visited = false;
			for (auto& j : str) {
				if (j == ' ') {
					vvvv.push_back(s);
					s = "";
				}
				else {
					s += j;
				}
			}
			for (int j = 0; j < vvvv.size(); j++) {
				if (!j) {
					string aa = "";
					for (int k = vvvv[j].length() - 1; k >= 0; k--) {
						if (isdigit(vvvv[j][k])) {
							aa += vvvv[j][k];
						}
						else {
							break;
						}
					}
					reverse(aa.begin(), aa.end());
					a = stoll(aa);
				}
				else {
					bool find = false;
					for (auto& k : vvvv[j]) {
						if (!isdigit(k)) {
							find = true;
							break;
						}
					}
					if (!find) {
						b = stoll(vvvv[j]);
						break;
					}
				}
			}
			vvv[b] = a;
		}
		string seq = "";
		str = "";
		getline(cin, seq);
		temp = 0;
		vector<string>vvvv;
		for (auto& i : seq) {
			if (i == ' ') {
				vvvv.push_back(str);
				str = "";
			}
			else {
				str += i;
			}
		}
		temp = stoll(vvvv.back());
		vector<string>result;
		vector<string>vvvvv;
		for (int i = 0; i < temp; i++) {
			string str = "";
			getline(cin, str);
			vvvvv.push_back(str);
		}
		for (auto& i : vvvvv) {
			ll idx = 0;
			ll depth = 0;
			string temp = "";
			bool a = false, b = false, c = false;
			for (auto& j : i) {
				if (j == '^') {
					idx++;
					depth--;
					temp += '^';
				}
				else if (j == 'v') {
					idx++;
					depth++;
					temp += 'v';
				}
				else if (j == '>') {
					idx++;
					temp += '>';
				}
				if (depth < 0) {
					if (!(a || b || c)) {
						a = true;
					}
				}
				else if (depth >= n) {
					if (!(a || b || c)) {
						b = true;
					}
				}
				else if (idx < m && depth >= n - vvv[idx]) {
					if (!(a || b || c)) {
						c = true;
					}
				}
			}
			if (a) {
				result.push_back("Sequence " + temp + " Crashed into tunnel ceiling");
			}
			else if (b) {
				result.push_back("Sequence " + temp + " Crashed into tunnel floor");
			}
			else if (c) {
				result.push_back("Sequence " + temp + " Crashed into stalagmite");
			}
			else {
				result.push_back("Sequence " + temp + " Reached end of tunnel");
			}
		}
		cout << "Case: " << count++ << '\n';
		for (auto& i : result) {
			cout << i << '\n';
		}
		if (num) {
			getline(cin, str);
		}
	}
	return 0;
}