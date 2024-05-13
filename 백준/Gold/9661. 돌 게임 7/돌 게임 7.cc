#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[2] = { 1,-1 };
int ary[5] = { 1,1,-1,1,-1 };
int main(void)
{
	ll n = 0;
	cin >> n;
	if (n < 3)
	{
		if (dp[n - 1] == 1)
		{
			cout << "SK";
		}
		else
		{
			cout << "CY";
		}
	}
	else
	{
		if (ary[(n - 3) % 5] == 1)
		{
			cout << "SK";
		}
		else
		{
			cout << "CY";
		}
	}
}