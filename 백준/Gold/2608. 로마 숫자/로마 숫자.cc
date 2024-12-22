#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool visited[2001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a = "", b = "";
	cin >> a >> b;
	for (int i = 0; i < a.length() - 1; i++) {
		if (a[i] == 'I' && a[i + 1] == 'V') {
			n += 4;
			visited[i] = visited[i + 1] = true;
			i++;
		}
		else if (a[i] == 'I' && a[i + 1] == 'X') {
			n += 9;
			visited[i] = visited[i + 1] = true;
			i++;
		}
		else if (a[i] == 'X' && a[i + 1] == 'L') {
			n += 40;
			visited[i] = visited[i + 1] = true;
			i++;
		}
		else if (a[i] == 'X' && a[i + 1] == 'C') {
			n += 90;
			visited[i] = visited[i + 1] = true;
			i++;
		}
		else if (a[i] == 'C' && a[i + 1] == 'D') {
			n += 400;
			visited[i] = visited[i + 1] = true;
			i++;
		}
		else if (a[i] == 'C' && a[i + 1] == 'M') {
			n += 900;
			visited[i] = visited[i + 1] = true;
			i++;
		}
		else {
			if (a[i] == 'I') {
				n += 1;
				visited[i] = true;
			}
			else if (a[i] == 'V') {
				n += 5;
				visited[i] = true;
			}
			else if (a[i] == 'X') {
				n += 10;
				visited[i] = true;
			}
			else if (a[i] == 'L') {
				n += 50;
				visited[i] = true;
			}
			else if (a[i] == 'C') {
				n += 100;
				visited[i] = true;
			}
			else if (a[i] == 'D') {
				n += 500;
				visited[i] = true;
			}
			else if (a[i] == 'M') {
				n += 1000;
				visited[i] = true;
			}
		}
	}
	if (!visited[a.length() - 1]) {
		if (a[a.length() - 1] == 'I') {
			n += 1;
		}
		else if (a[a.length() - 1] == 'V') {
			n += 5;
		}
		else if (a[a.length() - 1] == 'X') {
			n += 10;
		}
		else if (a[a.length() - 1] == 'L') {
			n += 50;
		}
		else if (a[a.length() - 1] == 'C') {
			n += 100;
		}
		else if (a[a.length() - 1] == 'D') {
			n += 500;
		}
		else if (a[a.length() - 1] == 'M') {
			n += 1000;
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < b.length() - 1; i++) {
		if (b[i] == 'I' && b[i + 1] == 'V') {
			n += 4;
			visited[i] = visited[i + 1] = true;
			i++;
		}
		else if (b[i] == 'I' && b[i + 1] == 'X') {
			n += 9;
			visited[i] = visited[i + 1] = true;
			i++;
		}
		else if (b[i] == 'X' && b[i + 1] == 'L') {
			n += 40;
			visited[i] = visited[i + 1] = true;
			i++;
		}
		else if (b[i] == 'X' && b[i + 1] == 'C') {
			n += 90;
			visited[i] = visited[i + 1] = true;
			i++;
		}
		else if (b[i] == 'C' && b[i + 1] == 'D') {
			n += 400;
			visited[i] = visited[i + 1] = true;
			i++;
		}
		else if (b[i] == 'C' && b[i + 1] == 'M') {
			n += 900;
			visited[i] = visited[i + 1] = true;
			i++;
		}
		else {
			if (b[i] == 'I') {
				n += 1;
				visited[i] = true;
			}
			else if (b[i] == 'V') {
				n += 5;
				visited[i] = true;
			}
			else if (b[i] == 'X') {
				n += 10;
				visited[i] = true;
			}
			else if (b[i] == 'L') {
				n += 50;
				visited[i] = true;
			}
			else if (b[i] == 'C') {
				n += 100;
				visited[i] = true;
			}
			else if (b[i] == 'D') {
				n += 500;
				visited[i] = true;
			}
			else if (b[i] == 'M') {
				n += 1000;
				visited[i] = true;
			}
		}
	}
	if (!visited[b.length() - 1]) {
		if (b[b.length() - 1] == 'I') {
			n += 1;
		}
		else if (b[b.length() - 1] == 'V') {
			n += 5;
		}
		else if (b[b.length() - 1] == 'X') {
			n += 10;
		}
		else if (b[b.length() - 1] == 'L') {
			n += 50;
		}
		else if (b[b.length() - 1] == 'C') {
			n += 100;
		}
		else if (b[b.length() - 1] == 'D') {
			n += 500;
		}
		else if (b[b.length() - 1] == 'M') {
			n += 1000;
		}
	}
	cout << n << '\n';
	while (n > 0) {
		if (n >= 1000) {
			cout << "M";
			n -= 1000;
		}
		else if (n >= 900) {
			cout << "CM";
			n -= 900;
		}
		else if (n >= 500) {
			cout << "D";
			n -= 500;
		}
		else if (n >= 400) {
			cout << "CD";
			n -= 400;
		}
		else if (n >= 100) {
			cout << "C";
			n -= 100;
		}
		else if (n >= 90) {
			cout << "XC";
			n -= 90;
		}
		else if (n >= 50) {
			cout << "L";
			n -= 50;
		}
		else if (n >= 40) {
			cout << "XL";
			n -= 40;
		}
		else if (n >= 10) {
			cout << "X";
			n -= 10;
		}
		else if (n >= 9) {
			cout << "IX";
			n -= 9;
		}
		else if (n >= 5) {
			cout << "V";
			n -= 5;
		}
		else if (n >= 4) {
			cout << "IV";
			n -= 4;
		}
		else if (n >= 1) {
			cout << "I";
			n -= 1;
		}
	}
	return 0;
}