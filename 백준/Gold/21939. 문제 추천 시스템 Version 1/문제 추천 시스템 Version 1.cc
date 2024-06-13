#include <bits/stdc++.h>
using namespace std;
int diff[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	priority_queue<pair<int, int>, vector<pair<int, int>>>maxq;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minq;
	for (int i = 0; i < n; i++) {
		int number = 0, hard = 0;
		cin >> number >> hard;
		diff[number] = hard;
		maxq.push({ hard, number });
		minq.push({ hard, number });
	}
	int m = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string command = "";
		cin >> command;
		if (command == "recommend") {
			int x = 0;
			cin >> x;
			if (x == 1) {
				while (diff[maxq.top().second] == 0 || maxq.top().first != diff[maxq.top().second]) {
					maxq.pop();
				}
				cout << maxq.top().second << '\n';
			}
			else if (x == -1) {
				while (diff[minq.top().second] == 0 || minq.top().first != diff[minq.top().second]) {
					minq.pop();
				}
				cout << minq.top().second << '\n';
			}
		}
		else if (command == "add") {
			int p = 0, l = 0;
			cin >> p >> l;
			diff[p] = l;
			maxq.push({ l, p });
			minq.push({ l, p });
		}
		else if (command == "solved") {
			int p = 0;
			cin >> p;
			diff[p] = 0;
		}
	}
}