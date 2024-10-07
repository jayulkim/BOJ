#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<string>v;
	string str = "";
	cout << fixed;
	cout.precision(4);
	while (getline(cin, str))
	{
		v.push_back(str);
		str = "";
	}
	sort(v.begin(), v.end());
	v.push_back(" ");
	int count = 1;
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] != v[i + 1])
		{
			cout << v[i] << ' ' << (double)count * 100 / (double)(v.size() - 1)<< '\n';
			count = 1;
		}
		else
		{
			count++;
		}
	}
	return 0;
}