#include <bits/stdc++.h>
using namespace std;
void cut(int n)
{
	if (n == 1)
	{
		cout << '-';
		return;
	}
	cut(n / 3);
	for (int i = 0; i < n / 3; i++)
	{
		cout << ' ';
	}
	cut(n / 3);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	while (cin >> n)
	{
		cut(pow(3, n));
		cout << '\n';
	}
	return 0;
}