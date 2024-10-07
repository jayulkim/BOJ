#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int size = 0;
		string num = "";
		int sum = 0;
		cin >> size >> num;
		if (size == 1)
		{
			cout << 6 << ' ' << 3 << '\n';
		}
		else
		{
			for (int j = 0; j < size; j++)
			{
				sum += (int)(num[j] - '0');
			}
			int num1 = sum % 3;
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++)
				{
					if (k == j)
					{
						if ((int)(num[k] - num1 - '0') <= 0)
						{
							cout << (int)(num[k] - num1 - '0') + 3;
						}
						else
						{
							cout << (int)(num[k] - num1 - '0');
						}
					}
					else
					{
						cout << num[k];
					}
				}
				cout << ' ' << 3 << '\n';
			}
		}
	}
	return 0;
}