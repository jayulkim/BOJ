#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[5] = {1,-1,1,1};
int ary[7] = { 1,1,-1,1,-1,1,1 };
int main(void)
{
	ll n = 0;
	cin >> n;
	if (n < 5)
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
		if (ary[(n - 5) % 7] == 1)
		{
			cout << "SK";
		}
		else
		{
			cout << "CY";
		}
	}
}