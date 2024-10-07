#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	cin >> str;
	vector<string>v;
	for (int i = 0; i < str.length() - 2; i++)
	{
		for (int j = i + 1; j < str.length() - 1; j++)
		{
			string factor1 = "";
			for (int k = i; k >= 0; k--)
			{
				factor1 += str[k];
			}
			string factor2 = "";
			for (int k = j; k >= i + 1; k--)
			{
				factor2 += str[k];
			}
			string factor3 = "";
			for (int k = str.length() - 1; k >= j + 1; k--)
			{
				factor3 += str[k];
			}
			string result = factor1 + factor2 + factor3;
			v.push_back(result);
		}
	}
	sort(v.begin(), v.end());
	cout << v.front();
}