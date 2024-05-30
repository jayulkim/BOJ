#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n = 0, k = 0;
	cin >> n >> k;
	string str = "";
	cin >> str;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'P')
		{
			int start = 0;
			int end = n - 1;
			if (i - k >= 0)
			{
				start = i - k;
			}
			if (i + k < n)
			{
				end = i + k;
			}
			bool eat = false;
			for (int j = start; j < i; j++)
			{
				if (str[j] == 'H' && !eat)
				{
					str[j] = 'E';
					eat = true;
					count++;
					break;
				}
			}
			for (int j = i + 1; j <= end; j++)
			{
				if (str[j] == 'H' && !eat)
				{
					str[j] = 'E';
					eat = true;
					count++;
					break;
				}
			}

		}
	}
	cout << count;
	return 0;
}