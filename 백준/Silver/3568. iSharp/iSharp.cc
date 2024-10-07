#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	getline(cin, str);
	istringstream ss(str);
	vector<string>v;
	string factor = "";
	while (getline(ss, factor, ' '))
	{
		v.push_back(factor);
	}
	for (int i = 1; i < v.size(); i++)
	{
		string New = v[0];
		if (v[i].back() == ',' || v[i].back() == ';')
		{
			v[i].pop_back();
		}
		for (int j = v[i].length() - 1; j >= 0; j--)
		{
			if ((v[i][j] >= 'a' && v[i][j] <= 'z') || (v[i][j] >= 'A' && v[i][j] <= 'Z'))
			{
				break;
			}
			New += v[i][j];
			v[i].pop_back();
		}
		v[i] = New + ' ' + v[i] + ';';
		int count = 1;
		for (int j = 0; j < v[i].length() - 1; j++)
		{
			if (v[i][j] == '[')
			{
				if (count != 1)
				{
					v[i][j] = ']';
					count = 1;
				}
				else
				{
					count = 2;
				}		
			}
			else if (v[i][j] == ']')
			{
				if (count != 2)
				{
					v[i][j] = '[';
					count = 2;
				}
				else
				{
					count = 1;
				}
			}
		}
		cout << v[i] << '\n';
	}
}