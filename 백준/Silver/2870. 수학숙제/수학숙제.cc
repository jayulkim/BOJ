#include <bits/stdc++.h>
using namespace std;
bool compare(const string num1, const string num2)
{
	if (num1.length() == num2.length())
	{
		return num1 < num2;
	}
	return num1.length() < num2.length();
}
int main(void)
{
	int n = 0;
	cin >> n;
	vector<string>v(n);
	vector<string>result;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		v[i].push_back('\0');
		int count = 0;
		while (count < v[i].length())
		{
			string integer = "";
			for (int j = count; j < v[i].length(); j++)
			{
				if (v[i][j] <= '9' && v[i][j] >= '0')
				{
					integer += v[i][j];
					v[i][j] = 'a';
				}
				else
				{	
					stack<char>s;
					string result1 = "";
					if (integer != "")
					{
						int count1 = 0;
						for (int j = integer.length() - 1; j >= 0; j--)
						{
							if (integer[j] != '0')
							{
								count1++;
								break;
							}
						}
						if (count1 == 0)
						{
							result.push_back("0");
						}
						else
						{
							for (int j = integer.length() - 1; j >= 0; j--)
							{
								int count2 = 0;
								for (int k = j; k >= 0; k--)
								{
									if (integer[k] != '0')
									{
										count2++;
										break;
									}
								}
								if (count2 == 0)
								{
									break;
								}
								s.push(integer[j]);
							}
							while (!s.empty())
							{
								result1 += s.top();
								s.pop();
							}
							if (result1 != "")
							{
								result.push_back(result1);
							}
						}
						
					}
					count++;
					break;
				}
			}
		}
	}
	sort(result.begin(), result.end(), compare);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}
	return 0;
}