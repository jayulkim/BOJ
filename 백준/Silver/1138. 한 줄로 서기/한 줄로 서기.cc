#include <bits/stdc++.h>
using namespace std;
int ary[11];
int result[11];
int visited[11];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];
		result[i] = i + 1;
	}
	int target = 1;
	while (target <= n)
	{
		for (int i = 0; i < n; i++)
		{
			if (result[i] == target)
			{
				int start = i;
				int end = i;
				int count = 0;
				for (int j = 0; j < i; j++)
				{
					if (result[j] > result[i])
					{
						count++;
					}
				}
				while (count < ary[target - 1])
				{
					for (int j = start + 1; j < n; j++)
					{
						if (visited[result[j]] == 0 && result[start] < result[j])
						{
							swap(result[start], result[j]);
							start = j;
							break;
						}
					}
					count++;
				}
				while (count > ary[target - 1])
				{
					for (int j = end - 1; j >= 0; j--)
					{
						if (visited[result[j]] == 0 && result[end] > result[j])
						{
							swap(result[end], result[j]);
							end = j;
							break;
						}
					}
					count--;
				}
				visited[target] = 1;
			}
		}
		target++;
	}
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << ' ';
	}
	return 0;
}