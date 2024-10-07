#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num1 = 0;
	cin >> num1;
	long long int sum = 0;
	int count = 0;
	long long int temp = 0;
	for (int i = 0; i < num1; i++)
	{
		long long int num2 = 0;
		cin >> num2;
		long long int num3 = 0;
		switch (num2)
		{
			case 1:
			{		
				cin >> num3;
		
				sum += num3;
				if (count == 0)
				{
					temp = num3;
					count++;
				}
				else
				{
					temp ^= num3;
				}
				break;
			}
			case 2:
			{
				cin >> num3;
				sum -= num3;
				if (count == 0)
				{
					temp = num3;
					count++;
				}
				else
				{
					temp ^= num3;
				}
				break;
			}
			case 3:
			{
				cout << sum << "\n";
				break;
			}
			case 4:
			{

				cout << temp << "\n";
				break;
			}
		}
	}
}