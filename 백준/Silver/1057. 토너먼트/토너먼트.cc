#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, jimin = 0, hansoo = 0;
	cin >> n >> jimin >> hansoo;
	int count = 0;
	while (jimin != hansoo)
	{
		jimin++;
		jimin /= 2;
		hansoo++;
		hansoo /= 2;
		count++;
	}
	cout << count;
}