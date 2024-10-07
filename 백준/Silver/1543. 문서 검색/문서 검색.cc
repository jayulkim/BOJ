#include <bits/stdc++.h>
using namespace std; 
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	getline(cin, str);
	string search = "";
	getline(cin, search);
	int count = 0;
	int idx = 0;
	while (idx < str.length() && str.find(search, idx) != -1)
	{
		idx = str.find(search, idx) + search.length();
		count++;
	}
	cout << count;
}