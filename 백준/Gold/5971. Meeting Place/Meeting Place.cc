#include <bits/stdc++.h>
using namespace std;
int parent[1001];
string str = "";
string temp = "";
void getParent(int x) {
	str[x] = '1';
	if (x == 1) {
		return;
	}
	getParent(parent[x]);
}
void merge(int a, int b) {
	parent[a] = b;
}
void minParent(int x) {
	if (str[x] == '1') {
		cout << x << '\n';
		str = temp;
		return;
	}
	minParent(parent[x]);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		str += '0';
	}
	str += '0';
	temp = str;
	for (int i = 2; i <= n; i++) {
		int num = 0;
		cin >> num;
		parent[i] = num;
	}
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		getParent(start);
		minParent(end);
	}
	return 0;
}