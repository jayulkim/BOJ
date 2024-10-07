#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compare(const string& a, const string& b) {
	return a.length() < b.length();
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<string>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), compare);
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (min(v[i].length(), v[j].length()) >= 1) {
				bool Find = false;
				string a = "", b = "";
				for (int k = 0; k < v[i].length(); k++) {
					a += v[i][k];
					b += v[j][v[j].length() - 1 - k];
					bool find = false;
					for (int u = 0; u < a.length(); u++) {
						if (a[u] != b[a.length() - 1 - u]) {
							find = true;
							break;
						}
					}
					if (!find) {
						Find = true;
						break;
					}
				}
				a = "", b = "";
				for (int k = 0; k < v[i].length(); k++) {
					a += v[j][k];
					b += v[i][v[i].length() - 1 - k];
					bool find = false;
					for (int u = 0; u < a.length(); u++) {
						if (a[u] != b[a.length() - 1 - u]) {
							find = true;
							break;
						}
					}
					if (!find) {
						Find = true;
						break;
					}
				}
				if (Find) {
					count++;
				}
			}
		}
	}
	cout << count;
	return 0;
}