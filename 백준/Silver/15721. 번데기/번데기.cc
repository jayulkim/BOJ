#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a = 0, t = 0, target = 0;
	cin >> a;
	cin >> t;
	cin >> target;
	int n = -1;
	int count0 = 0;
	int count1 = 0;
	int idx = 2;
	vector<int>v;
	while (1)
	{
		v.push_back(0);
		n = (n + 1) % a;
		count0++;
		if (target == 0 && t == count0 || target == 1 && t == count1)
		{
			cout << n;
			return 0;
		}
		v.push_back(1);
		n = (n + 1) % a;
		count1++;
		if (target == 0 && t == count0 || target == 1 && t == count1)
		{
			cout << n;
			return 0;
		}
		v.push_back(0);
		n = (n + 1) % a;
		count0++;
		if (target == 0 && t == count0 || target == 1 && t == count1)
		{
			cout << n;
			return 0;
		}
		v.push_back(1);
		n = (n + 1) % a;
		count1++;
		if (target == 0 && t == count0 || target == 1 && t == count1)
		{
			cout << n;
			return 0;
		}
		for (int i = 0; i < idx; i++)
		{
			v.push_back(0);
			n = (n + 1) % a;
			count0++;
			if (target == 0 && t == count0 || target == 1 && t == count1)
			{
				cout << n;
				return 0;
			}
		}
		for (int i = 0; i < idx; i++)
		{
			v.push_back(1);
			n = (n + 1) % a;
			count1++;
			if (target == 0 && t == count0 || target == 1 && t == count1)
			{
				cout << n;
				return 0;
			}
		}
		idx++;
	}
	return 0;
}