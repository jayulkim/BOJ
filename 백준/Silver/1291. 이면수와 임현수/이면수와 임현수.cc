#include <bits/stdc++.h>
using namespace std;
int ary[2701];
int prime[1111];
bool visited[2701];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i * i <= 2700; i++) {
		if (!ary[i]) {
			for (int j = i * i; j <= 2700; j += i) {
				ary[j] = 1;
			}
		}
	}
	int idx = 0;
	for (int i = 2; i <= 2700; i++) {
		if (!ary[i]) {
			prime[idx++] = i;
		}
	}
	int n = 0;
	cin >> n;
	for (int i = 1; i <= 100; i++) {

	}
	int sum = 0;
	int temp = n;
	while (temp > 0) {
		sum += temp % 10;
		temp /= 10;
	}
	bool lee = false;
	bool im = false;
	if (sum % 2 == 1 && (n >= 4 && n != 5)) {
		lee = true;
	}
	temp = n;
	int i = 0;
	int count = 0;
	while (temp > 1) {
		if (temp % prime[i] == 0) {
			temp /= prime[i];
			visited[prime[i]] = true;
		}
		else {
			i++;
		}
	}
	for (int i = 2; i <= 2700; i++) {
		if (visited[i]) {
			count++;
		}
	}
	if ((count % 2 == 0 && ary[n]) || n == 4 || n == 2) {
		im = true;
	}
	if (im && lee) {
		cout << 4;
	}
	else if (lee) {
		cout << 1;
	}
	else if (im) {
		cout << 2;
	}
	else {
		cout << 3;
	}
	return 0;
}