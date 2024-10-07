#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n = 0, m = 0, k = 0;
	cin >> n >> m;
	cin >> k;
	int start = 1;
	int end = m;
	int count = 0;
	for (int i = 0; i < k; i++)
	{
		int num = 0;
		cin >> num;
		while (num > end)
		{
			start++;
			end++;
			count++;
		}
		while (num < start)
		{
			end--;
			start--;
			count++;
		}
	}
	cout << count;
	return 0;
}