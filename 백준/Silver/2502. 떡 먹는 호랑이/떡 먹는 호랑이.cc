#include <bits/stdc++.h>
using namespace std;
int dp1[31];
int dp2[31];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int d = 0, num = 0;
	cin >> d >> num;
	dp1[1] = 1;
	dp1[2] = 1;
	dp1[3] = 1;
	dp1[4] = 1;
	for (int i = 5; i <= 30; i++)
	{
		dp1[i] = dp1[i - 1] + dp1[i - 2];
	}
	dp2[1] = 1;
	dp2[2] = 1;
	dp2[3] = 1;
	dp2[4] = 2;
	for (int i = 5; i <= 30; i++)
	{
		dp2[i] = dp2[i - 1] + dp2[i - 2];
	}
	int a1 = dp1[d], a2 = dp2[d];
	for (int i = 1; i <= 100000; i++)
	{
		if ((num - a1 * i) % a2 == 0)
		{
			cout << i << '\n' << (num - a1 * i) / a2;
			return 0;
		}
	}
	return 0;
}