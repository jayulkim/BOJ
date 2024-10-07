#include <bits/stdc++.h>
using namespace std;
bool visited[151];
int main(void)
{
	string str = "";
	cin >> str;
	int len = str.length();
	if (len == 1)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < len; i++)
	{
		visited[(int)str[i]] = true;
	}
	int count = 0;
	for (int i = 0; i < 150; i++)
	{
		if (visited[i] == true)
		{
			count++;
		}
	}
	if (count == 1)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
		{
			cout << len;
			return 0;
		}
	}
	cout << len - 1;
	return 0;
}