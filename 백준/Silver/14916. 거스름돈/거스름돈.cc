#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int>v;
	int num = 0;
	cin >> num;
	int num1 = num;
	if (num == 1)
	{
		cout << -1;
		return 0;
	}
	else if (num == 2)
	{
		cout << 1;
		return 0;
	}
	int count = 0;
	int idx = -1;
	while (num1 > 0)
	{
		if (num1 - 5 >= 0)
		{
			v.push_back(num1 - 5);
		}
		num1 -= 5;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] % 2 == 0)
		{
			idx = i + 1;
		}
	}
	if (idx != -1)
	{
		count += idx;
		num = v[idx - 1];
	}
	if (num % 2 != 0)
	{
		cout << -1;
		return 0;
	}
	count += num / 2;
	cout << count;
	return 0;
}