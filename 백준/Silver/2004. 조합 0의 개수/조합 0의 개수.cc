#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll up1 = 0, up2 = 0, down1 = 0, down2 = 0;
	ll temp = n, k = 2;
	while (temp > 0) {
		up1 += (n / k);
		k *= 2;
		temp /= 2;
	}
	temp = n, k = 5;
	while (temp > 0) {
		up2 += (n / k);
		k *= 5;
		temp /= 5;
	}
	temp = m, k = 2;
	while (temp > 0) {
		down1 += (m / k);
		k *= 2;
		temp /= 2;
	}
	temp = m, k = 5;
	while (temp > 0) {
		down2 += (m / k);
		k *= 5;
		temp /= 5;
	}
	temp = n - m, k = 2;
	while (temp > 0) {
		down1 += ((n - m) / k);
		k *= 2;
		temp /= 2;
	}
	temp = n - m, k = 5;
	while (temp > 0) {
		down2 += ((n - m) / k);
		k *= 5;
		temp /= 5;
	}
	up1 -= down1;
	up2 -= down2;
	cout << min(up1, up2);
	return 0; 
}