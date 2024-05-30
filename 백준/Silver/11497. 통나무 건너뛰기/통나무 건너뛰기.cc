#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int num = 0;
	cin >> num;
	vector<int>v;
	vector<int>result;
	while (num--)
	{
		int n = 0;
		cin >> n;
		v.resize(n);
		result.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		if (n % 2 == 0)
		{
			int idx = 0;
			int resultidx = 0;
			while (idx < n)
			{
				result[resultidx] = v[idx];
				idx++;
				result[n - resultidx - 1] = v[idx];
				idx++;
				resultidx++;
			}
			int Max = abs(result[0] - result[n - 1]);
			for (int i = 0; i < n - 1; i++)
			{
				Max = max(Max, abs(result[i] - result[i + 1]));
			}
			cout << Max << '\n';
		}
		else
		{
			int idx = 0;
			int resultidx = 0;
			while (idx < n - 1)
			{
				result[resultidx] = v[idx];
				idx++;
				result[n - resultidx - 1] = v[idx];
				idx++;
				resultidx++;
			}
			result[n / 2] = v[n - 1];
			int Max = abs(result[0] - result[n - 1]);
			for (int i = 0; i < n - 1; i++)
			{
				Max = max(Max, abs(result[i] - result[i + 1]));
			}
			cout << Max << '\n';
		}
	}
	return 0;
}