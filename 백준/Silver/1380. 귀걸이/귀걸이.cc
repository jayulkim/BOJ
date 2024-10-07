#include <bits/stdc++.h>
using namespace std;
bool visited[101];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int count = 1;
	while (1) {
		int n = 0;
		cin >> n;
		if (n == 0) {
			break;
		}
		cin.ignore();
		vector<string>v(n + 1);
		for (int i = 1; i <= n; i++) {
			getline(cin, v[i]);
		}
		for (int i = 0; i < 2 * n - 1; i++) {
			int num = 0;
			char ab;
			cin >> num >> ab;
			visited[num] = !visited[num];
		}
		for (int i = 1; i <= n; i++) {
			if (visited[i]) {
				cout << count << ' ' << v[i] << '\n';
			}
		}
		count++;
		memset(visited, false, sizeof(visited));
	}
	return 0;
}