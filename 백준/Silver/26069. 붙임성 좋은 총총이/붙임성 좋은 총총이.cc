#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0; 
	cin >> n;
	unordered_set<string>s;
	for (int i = 0; i < n; i++)
	{
		string name1 = "";
		string name2 = "";
		cin >> name1 >> name2;
		if (name1 == "ChongChong" || name2 == "ChongChong")
		{
			s.insert(name1);
			s.insert(name2);
		}
		else
		{
			if (s.find(name1) != s.end())
			{
				s.insert(name2);
			}
			if (s.find(name2) != s.end())
			{
				s.insert(name1);
			}
		}
	}
	cout << s.size();
}