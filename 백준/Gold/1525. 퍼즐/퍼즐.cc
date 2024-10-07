#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, ll>Map;
struct info {
	string ary;
	ll x;
	ll count;
};
bool Find = false;
void bfs(string start) {
	Map[start]++;
	queue<info>q;
	ll x = 0;
	for (int i = 0; i < 9; i++) {
		if (start[i] == '0') {
			x = i;
		}
	}
	q.push({ start, x, 0 });
	while (!q.empty()) {
		info temp = q.front();
		q.pop();
		Map[temp.ary] = temp.count;
		if (temp.x == 0) {
			string str = temp.ary;
			swap(str[temp.x], str[1]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 1, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[3]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 3, temp.count + 1 });
			}
		}
		else if (temp.x == 1) {
			string str = temp.ary;
			swap(str[temp.x], str[0]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 0, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[2]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 2, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[4]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 4, temp.count + 1 });
			}
		}
		else if (temp.x == 2) {
			string str = temp.ary;
			swap(str[temp.x], str[1]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 1, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[5]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 5, temp.count + 1 });
			}
		}
		else if (temp.x == 3) {
			string str = temp.ary;
			swap(str[temp.x], str[0]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 0, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[4]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 4, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[6]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 6, temp.count + 1 });
			}
		}
		else if (temp.x == 4) {
			string str = temp.ary;
			swap(str[temp.x], str[1]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 1, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[3]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 3, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[5]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 5, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[7]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 7, temp.count + 1 });
			}
		}
		else if (temp.x == 5) {
			string str = temp.ary;
			swap(str[temp.x], str[2]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 2, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[4]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 4, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[8]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 8, temp.count + 1 });
			}
		}
		else if (temp.x == 6) {
			string str = temp.ary;
			swap(str[temp.x], str[3]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 3, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[7]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 7, temp.count + 1 });
			}
		}
		else if (temp.x == 7) {
			string str = temp.ary;
			swap(str[temp.x], str[6]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 6, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[4]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 4, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[8]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 8, temp.count + 1 });
			}
		}
		else if (temp.x == 8) {
			string str = temp.ary;
			swap(str[temp.x], str[7]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 7, temp.count + 1 });
			}
			str = temp.ary;
			swap(str[temp.x], str[5]);
			if (!Map[str]) {
				Map[str]++;
				q.push({ str, 5, temp.count + 1 });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	bfs("123456780");
	string str = "";
	for (int i = 0; i < 9; i++) {
		char temp;
		cin >> temp;
		str += temp;
	}
	if (str == "123456780") {
		cout << 0;
	}
	else {
		if (!Map[str]) {
			cout << -1;
		}
		else {
			cout << Map[str];
		}
	}
	return 0;
}