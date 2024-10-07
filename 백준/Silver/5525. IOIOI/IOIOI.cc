#include <bits/stdc++.h>
using namespace std; 
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, level = 0;
	cin >> level >> n;
	string str = "";
	string search = "";
	cin >> str;
	for (int i = 0; i < level; i++)
	{
		search += 'I';
		search += 'O';
	}
	search += 'I';
	if (str.find(search, 0) == -1)
	{
		cout << 0;
		return 0;
	}
	int count = 1;
	int idx = str.find(search, 0) + search.length() - 1;
	while (idx < n)
	{
		if (idx + 2 < n && str[idx + 1] == 'O' && str[idx + 2] == 'I')
		{
			count++;
			idx += 2;
		}
		else
		{
			if (str.find(search, idx) == -1)
			{
				cout << count;
				return 0;
			}
			else
			{
				count++;
				idx = str.find(search, idx) + search.length() - 1;
			}
		}
	}
	cout << count;
	return 0;
}