#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0; 
	cin >> n;
	int count = 0;
	unordered_set<string>s;
	for (int i = 0; i < n; i++)
	{
		string str = "";
		cin >> str;
		if (str == "ENTER")
		{
			unordered_set<string>().swap(s);
		}
		else
		{
			if (s.find(str) == s.end())
			{
				count++;
				s.insert(str);
			}
		}
	}
	cout << count;
}