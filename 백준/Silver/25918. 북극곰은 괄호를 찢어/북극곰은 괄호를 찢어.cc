#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	stack<char> stack;
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	int n = 0;
	cin >> n >> str;	
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (!stack.empty() && str[i] == ')' && stack.top() == '(')
		{
			stack.pop();
		}
		else if (!stack.empty() && str[i] == '(' && stack.top() == ')')
		{
			stack.pop();
		}
		else
		{
			stack.push(str[i]);
		}
		if (max < stack.size())
		{
			max = stack.size();
		}
	}
	if (stack.empty())
	{
		cout << max;
	}
	else
	{
		cout << -1;
	}
}