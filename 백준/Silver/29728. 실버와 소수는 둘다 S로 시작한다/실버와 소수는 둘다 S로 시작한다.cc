#include <bits/stdc++.h>
using namespace std;
int ary[5000001];
int Reverse = 0;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ary[1] = 1;
	for (int i = 2; i * i <= 5000000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 5000000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int n = 0;
	cin >> n;
	deque<char>dq;
	for (int i = 1; i <= n; i++)
	{
		if (ary[i] == 0)
		{
			if (Reverse == 0)
			{
				if (!dq.empty() && dq.back() == 'B')
				{
					dq.pop_back();
					dq.push_back('S');
					dq.push_back('S');
				}
				else
				{
					dq.push_back('S');
					Reverse = 1;
				}
			}
			else
			{
				if (!dq.empty() && dq.front() == 'B')
				{
					dq.pop_front();
					dq.push_front('S');
					dq.push_front('S');
				}
				else
				{
					dq.push_front('S');
					Reverse = 0;
				}
			}
		}
		else
		{
			if (Reverse == 0)
			{
				dq.push_back('B');
			}
			else
			{
				dq.push_front('B');
			}
		}
	}
	int b = 0, s = 0;
	while (!dq.empty())
	{
		if (dq.back() == 'B')
		{
			b++;
		}
		else if (dq.back() == 'S')
		{
			s++;
		}
		dq.pop_back();
	}
	cout << b << ' ' << s;
	return 0;
}