#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<string>v(n);
	map<string, int>m;
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		len = v[i].length();
	}
	int result = 1;
	while (1)
	{
		int stop = 0;
		for (int i = 0; i < n; i++)
		{
			string str = "";
			for (int j = 0; j < result; j++)
			{
				str.push_back(v[i][len - j - 1]);
			}
			if (m.find(str) != m.end())
			{
				stop++;
				break;
			}
			m.insert({ str, 0 });
		}
		if (stop == 0)
		{
			cout << result;
			return 0;
		}
		result++;
	}
	return 0;
}