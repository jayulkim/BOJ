#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	string str = "";
	getline(cin, str);
	int count = 0;
	stack<char>s;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '<')
		{
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			cout << str[i];
			count = 1;
		}
		else if (str[i] == '>')
		{
			cout << str[i];
			count = 0;
		}
		else
		{
			if (count == 1)
			{
				cout << str[i];
			}
			else
			{
				if (str[i] == ' ')
				{
					while (!s.empty())
					{
						cout << s.top();
						s.pop();
					}
					cout << ' ';
				}
				else
				{
					s.push(str[i]);
				}	
			}
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}