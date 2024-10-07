#include <bits/stdc++.h>
using namespace std;
int visited[131];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	string str = "";
	cin >> n;
	cin >> str;
	if (n % 2 == 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (i != n / 2)
			{
				visited[(int)str[i]]++;
			}
		}
		int count = 0;
		for (int i = 0; i <= 130; i++)
		{
			if (visited[i] % 2 == 1)
			{
				count++;
				break;
			}
		}
		if (count == 0)
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			visited[(int)str[i]]++;
		}
		int count = 0;
		for (int i = 0; i <= 130; i++)
		{
			if (visited[i] % 2 == 1)
			{
				count++;
				break;
			}
		}
		if (count == 0)
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}
	
}