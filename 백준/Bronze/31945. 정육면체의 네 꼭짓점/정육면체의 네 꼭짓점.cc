#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int num = 0;
	cin >> num;
	vector<int>v(4);
	while (num--)
	{
		for (int i = 0; i < 4; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		if (v[0] == 0 && v[1] == 1 && v[2] == 4 && v[3] == 5)
		{
			cout << "YES\n";
		}
		else if (v[0] == 0 && v[1] == 1 && v[2] == 2 && v[3] == 3)
		{
			cout << "YES\n";
		}
		else if (v[0] == 1 && v[1] == 3 && v[2] == 5 && v[3] == 7)
		{
			cout << "YES\n";
		}
		else if (v[0] == 4 && v[1] == 5 && v[2] == 6 && v[3] == 7)
		{
			cout << "YES\n";
		}
		else if (v[0] == 2 && v[1] == 3 && v[2] == 6 && v[3] == 7)
		{
			cout << "YES\n";
		}
		else if (v[0] == 0 && v[1] == 2 && v[2] == 4 && v[3] == 6)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}