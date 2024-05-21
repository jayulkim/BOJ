#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<ll>distence(n - 1);
	vector<ll>cost(n);
	ll dissum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> distence[i];
		dissum += distence[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}
	ll sum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (dissum * cost[i] > (dissum - distence[i]) * cost[i + 1] + cost[i] * distence[i])
		{
			sum += (distence[i] * cost[i]);
			dissum -= distence[i];
		}
		else
		{
			sum += (dissum * cost[i]);
			break;
		}
	}
	cout << sum;
}