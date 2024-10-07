#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<char>v;
	string result = "";
	string str = "";
	cin >> str;
	int num1 = str.length();
	for (int i = 0; i <= num1; i++)
	{
		if (str[i] == 'X')
		{
			v.push_back(str[i]);
		}
		else
		{
			if (v.size() % 4 == 0)
			{
				while (v.size() != 0)
				{
					result.push_back('A');
					v.pop_back();
				}
			}
			else if (v.size() % 4 == 2)
			{
				while (v.size() != 2)
				{
					result.push_back('A');
					v.pop_back();
				}
				result.push_back('B');
				result.push_back('B');
				v.pop_back();
				v.pop_back();
			}
			else
			{
				cout << -1;
				return 0;
			}
			if (i != num1)
			{
				result.push_back('.');
			}
		}
	}
	cout << result;
	return 0;
}