#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll visited[7][8];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = LLONG_MAX, m = LLONG_MAX;
	for (int i = 0; i < 21; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		for (int j = 0; j < 6; j++) {
			if (!visited[j][a - 1]) {
				visited[j][a - 1] = 1;
				break;
			}
		}
		for (int j = 0; j < 6; j++) {
			if (!visited[j][b - 1]) {
				visited[j][b - 1] = 2;
				break;
			}
		}
		for (int l = 0; l < 6; l++) {
			for (int u = 0; u < 7; u++) {
				if (n == LLONG_MAX && m == LLONG_MAX) {
					ll count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l;
						ll dx = u + k;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 1) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						n = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l + k;
						ll dx = u;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 1) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						n = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l;
						ll dx = u - k;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 1) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						n = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l - k;
						ll dx = u;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 1) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						n = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l + k;
						ll dx = u + k;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 1) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						n = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l - k;
						ll dx = u + k;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 1) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						n = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l + k;
						ll dx = u - k;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 1) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						n = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l - k;
						ll dx = u - k;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 1) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						n = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l;
						ll dx = u + k;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 2) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						m = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l + k;
						ll dx = u;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 2) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						m = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l;
						ll dx = u - k;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 2) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						m = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l - k;
						ll dx = u;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 2) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						m = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l + k;
						ll dx = u + k;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 2) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						m = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l - k;
						ll dx = u + k;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 2) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						m = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l + k;
						ll dx = u - k;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 2) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						m = i + 1;
					}
					count = 0;
					for (int k = 0; k < 4; k++) {
						ll dy = l - k;
						ll dx = u - k;
						if (dy >= 0 && dy < 6 && dx >= 0 && dx < 7 && visited[dy][dx] == 2) {
							count++;
						}
						else {
							break;
						}
					}
					if (count >= 4) {
						m = i + 1;
					}
				}
			}
		}
	}
	if (n < m) {
		cout << "sk " << n;
	}
	else if (m < n) {
		cout << "ji " << m;
	}
	else {
		cout << "ss";
	}
	return 0;
}