#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	unordered_set<string>memo;
	for (int i = 0; i < n; i++)
	{
		string str = "";
		cin >> str;
		memo.insert(str);
	}
	for (int i = 0; i < m; i++)
	{
		string str = "";
		string search = "";
		cin >> str;
		istringstream ss(str);
		while (getline(ss, search, ','))
		{
			if (memo.find(search) != memo.end())
			{
				memo.erase(search);
				n--;
			}
		}
		cout << n << '\n';
	}
}