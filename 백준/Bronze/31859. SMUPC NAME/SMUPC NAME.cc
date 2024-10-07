#include <bits/stdc++.h>
using namespace std;
int visited[301];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	string name = "";
	cin >> n >> name;
	string str = "";
	int count = 0;
	for (int i = 0; i < name.length(); i++)
	{
		if (visited[name[i] - 'a'] == 0)
		{
			str += name[i];
			visited[name[i] - 'a']++;
		}
		else
		{
			count++;
		}
	}
	count += 4;
	string del = to_string(count);
	str += del;
	n += 1906;
	string number = to_string(n);
	number += str;
	cout << "smupc_";
	for (int i = number.length() - 1; i >= 0; i--)
	{
		cout << number[i];
	}
}