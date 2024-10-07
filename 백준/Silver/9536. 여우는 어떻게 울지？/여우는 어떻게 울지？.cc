#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string str = "";
		map<string, int>m;
		getline(cin, str);
		str += ' ';
		vector<string>v;
		while (1)
		{
			string animal = "";
			getline(cin, animal);
			if (animal == "what does the fox say?")
			{
				break;
			}
			int idx = 0;
			for (int j = 0; j < animal.length(); j++)
			{
				if (animal[j] == 'g' && animal[j + 1] == 'o' && animal[j + 2] == 'e' && animal[j + 3] == 's')
				{
					idx = j + 5;
					break;
				}
			}
			string result = "";
			for (int j = idx; j < animal.length(); j++)
			{
				result += animal[j];
			}
			m.insert({ result, 0 });
		}
		int start = 0;
		while (start < str.length())
		{
			string result = "";
			for (int j = start; j < str.length(); j++)
			{
				if (str[j] != ' ')
				{
					result += str[j];
				}
				else
				{
					start = j + 1;
					break;
				}
			}
			v.push_back(result);
		}
		for (auto& i : v)
		{
			if (m.find(i) == m.end())
			{
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}