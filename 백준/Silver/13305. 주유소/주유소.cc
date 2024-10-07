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
	}
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}
	ll sum = 0;
	ll choice = cost[0];
	for (int i = 1; i < n; i++)
	{
		sum += (distence[i - 1] * choice);
		if (choice > cost[i])
		{
			choice = cost[i];
		}
	}
	cout << sum;
}