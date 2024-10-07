#include <bits/stdc++.h>
using namespace std;
int ary[500001];
bool visited[500001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int idx = 2;
	ary[1] = 1;
	for (int i = 2; i <= 500000; i++) {
		if (!ary[i]) {
			for (int j = i; j <= 500000; j += i) {
				ary[j] = idx;
			}
			idx++;
		}
	}
	int n = 0, count = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		visited[ary[i]] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			count++;
		}
	}
	cout << count << '\n';
	for (int i = 1; i <= n; i++) {
		cout << ary[i] << ' ';
	}
	return 0;
}