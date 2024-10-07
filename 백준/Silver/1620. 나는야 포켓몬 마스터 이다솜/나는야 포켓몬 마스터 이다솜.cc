#include <bits/stdc++.h>
using namespace std;
string name[100001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	map<string, int>map;
	int n = 0;
	int m = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> name[i];
		map.insert({ name[i], i + 1 });
	}
	for (int i = 0; i < m; i++)
	{
		string command = "";
		cin >> command;
		if (isdigit(command[0]))
		{
			int num1 = stoi(command);
			cout << name[num1 - 1] << '\n';
		}
		else
		{
			cout << map.find(command)->second << '\n';
		}
	}
}