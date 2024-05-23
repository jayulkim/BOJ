#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	cin >> str;
	stack<char>s;
	int sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else 
		{
			s.pop();
			if (str[i - 1] == '(')
			{
				sum += s.size();
			}
			else
			{
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}